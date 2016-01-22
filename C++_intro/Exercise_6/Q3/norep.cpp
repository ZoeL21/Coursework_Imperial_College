#include <iostream>

using namespace std;

//prototypes
void remove_repetitions(char array[]);
bool check_inside_store(char& character, char array[], int i);
void my_copy(char array[], char array_new[], int length);

int main()
{
  //define variable
  const int SIZE = 40;
  char array[SIZE];

  //getstring input from user
  cout<<"enter a string"<<endl;
  cin.getline(array, SIZE);

  remove_repetitions(array);

  //output string
  cout<<"repetition-free string: "<<endl;
  for(int i = 0; array[i] != '\0'; i++)
    {
      cout<<array[i];
    }
  cout<<endl;

    return 0;
}

//function definitions

/*FUNCTION TO REMOVE REPEATING LETTERS FROM STRING*/
void remove_repetitions(char array[])
{
  //determinde content size of array passed
  int size = 0;
  for(; array[size] != '\0'; size++);

  //create array store to store already seen characters
  int index_store = 0;
  char store[size];
  for(int i = 0; i < size; i++)
    {
      store[i] = 0;
    }

  //create new array to save string with no repetitions
  char new_array[size];
  int index_new = 0;

  //traverse array
  for(int i = 0; i < size; i++)
    {          
      //check if inside store array
      if(check_inside_store(array[i], store, i))
	{
	  continue;
	}
      else
	{
	  //put inside store
          store[index_store] = array[i];
	  //enter character into array containing no repetitions
          new_array[index_new] = array[i];
	  index_new++; index_store++;
	}
    }

  //length of array containoing no repetitions
  int length = index_new + 1;
  
  //add terminating character
  new_array[length] = '\0';
  
  //copy content of new array into the original array
  my_copy(array,new_array, length); 
}


/*FUNCTION TO CEHCK IF CHARACTER IN ARRAY IS ALREADY STORED INSIDE THE STORE ARRAY*/
  bool check_inside_store(char& character, char store[], int index)
  {

    for(int j = 0; j < index; j++)
      {
	if(character != store[j])
	  {
	    continue;
	  }
	else
	  {
	    return true;
	  }
      }
	return false;
  }


/*FUNCTION TO COPY ONE ARRAY INTO THE OTHER*/
void my_copy(char array[], char new_array[], int length)
{
  for(int i = 0; i < length; i++)
    {
      array[i] = new_array[i];
    }
}
