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

/*Recursive Function to print list forward*/
void print_forward(Node_ptr list);

/*Recursive Function to print list backwards*/
void print_backward(Node_ptr list);

/*Iterative version of print_backwards*/
void print_backward_it(Node_ptr list);

/* MAIN PROGRAM */
int main()
{
	Node_ptr my_list = NULL;

	assign_list(my_list);

	cout << "\nTHE LIST IS NOW:\n";
	print_list(my_list);

	
	//print forward
        cout<<"\nTHE LIST IS NOW:"<<endl;
	print_forward(my_list);

        //print backward
        cout<<"\nTHE LIST (backwards) IS NOW:"<<endl;
	print_backward(my_list);

return 0;
}
/* END OF MAIN PROGRAM */

/*FUNCTION DEFINITION OF "print_forward"*/
void print_forward(Node_ptr list)
{
  //base case
  if(list->ptr_to_next_node == NULL)
    {
      cout<<list->word<<endl;
      return;
    }

  cout<<list->word<<" ";
  list = list->ptr_to_next_node;
  //call function
  print_forward(list);  

}
/*END OF FUNCTION DEFINITION*/

/*FUNCTION DEFINITION OF "print_backward"*/
void print_backward(Node_ptr list)
{
  // Node_ptr save_first = list;
 
 //base case
  if(list->ptr_to_next_node == NULL)
    {
     cout<<list->word<<" ";
     return;
    }
  
  //call function
  print_backward(list->ptr_to_next_node);  
  cout<<list->word<<" ";
}
/*END OF FUNCTION DEFINITION*/

void print_backward_it(Node_ptr list)
{
  
  //go to very back of the list 
  
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
