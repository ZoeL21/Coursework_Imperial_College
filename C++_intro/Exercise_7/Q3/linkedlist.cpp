/* Program 7.5.1 from C++ Programming Lecture notes  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 28th September 2013    */

/* This program creates and prints out a linked list of strings. */ 

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

struct Node
{
	char word[MAX_WORD_LENGTH];
	Node_ptr ptr_to_next_node;
};

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

/*Function to delete a node*/
void delete_node(Node_ptr &a_list, char a_word[]);

/*Function to insert a word*/
void add_after(Node_ptr &list,char a_word[], char word_after[]);

/*Function to sort content of list*/
void list_selection_sort(Node_ptr &a_list);

int smaller(Node_ptr &current_node,Node_ptr &traverse);

/* MAIN PROGRAM */
int main()
{
	Node_ptr my_list = NULL;

	assign_list(my_list);

	cout << "\nTHE LIST IS NOW:\n";
	print_list(my_list);

	char word[MAX_WORD_LENGTH];
	char word_to_add[MAX_WORD_LENGTH];
	cout<<"add word: "<<endl;
		cin>>word_to_add;
	cout<<"after: "<<endl;
	cin>>word;
	add_after(my_list,word,word_to_add);
        cout << "\nTHE LIST IS NOW:\n";
	print_list(my_list);

	//delete a word
	char word_delete[MAX_WORD_LENGTH]; 
	cout<<"delete word: "<<endl;
	cin>>word_delete;
	delete_node(my_list,word_delete);
	cout<<"\nTHE LIST IS NOW:"<<endl;
	print_list(my_list);	

	//sort list
	list_selection_sort(my_list);
        cout<<"\nTHE LIST IS NOW:"<<endl;
	print_list(my_list);

return 0;
}
/* END OF MAIN PROGRAM */

/*DEFINITION OF FUNCTION "add_afer"*/
void add_after(Node_ptr &a_list, char a_word[], char add_after[])
{
  Node_ptr traverse = a_list;
  Node_ptr save_loc = NULL;

  //traverse list until first occurence found
  do
    {  
      save_loc = traverse;

    if(strcmp(traverse->word,a_word) == 0)
      {
	//create new node
	Node_ptr new_node = NULL;
	assign_new_node(new_node);

	//add word to node
	for(unsigned int i = 0; i < sizeof(a_word); i++)
	  {
	    new_node->word[i] = add_after[i];
	  }

	//check if end of the list is reached
	if(traverse->ptr_to_next_node == NULL)
	  {
	    //point pointer of current node to new node
	    traverse->ptr_to_next_node = new_node;
	    //point end of list to NULL
	    new_node->ptr_to_next_node = NULL;
	    //break out of loop
	    break;
	  }
	else
	  {
	    //point new_node pointer to list
	    new_node->ptr_to_next_node = traverse->ptr_to_next_node;
	    //point current node to new node
	    traverse->ptr_to_next_node = new_node;
	    //break out of loop
	    break;	    
          }
      }
    else
      {
	//continue
        traverse = traverse->ptr_to_next_node;
      }
     
    }while(save_loc->ptr_to_next_node != NULL);

}
/* END OF FUNCTION DEFINITION */

/*DEFINITON OF FUNCTION "delete_node" */
void delete_node(Node_ptr &a_list, char a_word[])
{
  Node_ptr traverse = a_list;
  Node_ptr save_loc = traverse;

  //traverse list until word is found
 while(strcmp(traverse->word, a_word) != 0) 
    {
      //if end of list reached, break
      if(traverse->ptr_to_next_node == NULL)
	{
	  break;
	}
      //continue
      save_loc = traverse;
      traverse = traverse->ptr_to_next_node;
    }

  cout<<"found word or reached end of list"<<endl;

   //found word or reached end of function
   if(strcmp(traverse->word, a_word) == 0)
     {
       cout<<"found word"<<endl;
       //check if end of list reached
       if(traverse->ptr_to_next_node == NULL)
	 {
	   cout<<"word is at end"<<endl;
	   //delete memory previous pointer is pointing to	     
	   save_loc->ptr_to_next_node = NULL;
           delete traverse;
	   
	 }
       else if(traverse == a_list)
	 {
	   cout<<"word is at beginning"<<endl;
	   //point a_list to next node
	   a_list = traverse->ptr_to_next_node;
	   //delete	  
	   delete traverse;
	 }
       else
	 {
	   cout<<"word is in the middle"<<endl;
	   //previous node to next node
	   save_loc->ptr_to_next_node = traverse->ptr_to_next_node;
	   //delete memory of word pointed to
	   delete traverse;	 
	 }
     }
   else
     {
       cout<<"word not found"<<endl;
     }
}
/* END OF FUNCTION DEFINITION */

/*DEFINITION OF FUNCTION"list_selection_sort"*/		 
void list_selection_sort(Node_ptr &a_list)
{
  Node_ptr current_node = a_list;
  Node_ptr traverse = current_node;
  Node_ptr save_pos = NULL;

  for(;current_node->ptr_to_next_node != NULL; current_node = current_node->ptr_to_next_node)
    {
      //reset traverse node
      traverse = current_node;
      
      //traverse function while current_node > last_node
      do
      {
	save_pos = traverse;
        if(smaller(current_node,traverse) <= 0)
	  {
            //traverse is smaller or equal than current node, continue
            traverse = traverse->ptr_to_next_node;
	  }
        else
	  {
	    //selected node is smaller than current node, change content
	    for(int i = 0; i < MAX_WORD_LENGTH; i++)
	      {
	        char temp = current_node->word[i];
	        current_node->word[i] = traverse->word[i];
	        traverse->word[i] = temp;
	      }	    
  	  }     
      }while(save_pos->ptr_to_next_node != NULL);
    }
}		 
/* END OF FUNCTION DEFINITION */		

int smaller(Node_ptr &current_node,Node_ptr &traverse)
{
  int result = strcmp(current_node->word,traverse->word);

  return result;
  
}
	
/* DEFINITION OF FUNCTION "assign_list" */
void assign_list(Node_ptr &a_list)
{
	Node_ptr current_node, last_node;
	
	assign_new_node(a_list);
	cout << "Enter first word (or '.' to end list): ";
	cin >> a_list->word;
	if (!strcmp(".",a_list->word))
	{
		delete a_list;
		a_list = NULL;
	}
	current_node = a_list;
	
	while (current_node != NULL)
	{
		assign_new_node(last_node);
		cout << "Enter next word (or '.' to end list): ";
		cin >> last_node->word;
		if (!strcmp(".",last_node->word))
		{
			delete last_node;
			last_node = NULL;
		}
		current_node->ptr_to_next_node = last_node;
		current_node = last_node;
	}
}	
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "assign_new_node" */
void assign_new_node(Node_ptr &a_node)
{
        a_node = new (nothrow) Node;
	if (a_node == NULL) 
	{
		cout << "sorry - no more memory\n"; 
		exit(1);
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "print_list" */
void print_list(Node_ptr a_node)
{
	while (a_node != NULL)
	{
		cout << a_node->word << " ";
		a_node = a_node->ptr_to_next_node;
	}
}
/* END OF FUNCTION DEFINITION */



