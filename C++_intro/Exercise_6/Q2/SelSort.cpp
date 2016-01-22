#include <iostream>


using namespace std;

//function prototypes
void swap(char& first, char& second);
void selectionsort(char array[]);
int minimum(int position, char array[]);


//global
int size = 0;

int main()
{

  const int SIZE = 20;
  char array[SIZE];

  //get input string from user
  cout<<"please input a string to be sorted:"<<endl;
  cin.getline(array,SIZE);

  //print the array read in
  for(int i = 0; array[i] != '\0'; i++)
    {
      cout<<array[i];
      size++;
    }
  cout<<endl;

  //sorting the array
  
  selectionsort(array);

 //print the sorted array  
  cout<<"sorted array:"<<endl;
  for(int i = 0; array[i] != '\0'; i++)
    {
      cout<<array[i];
      
    }
  cout<<endl;
  
  return 0;
}


void selectionsort(char array[])
{
  //traverse the array
  int index = 0;
  cout<<size<<endl;
  //char  c = array[index];
  // cout<<"element is: "<<array[index];

  for(; array[index] != '\0'; index++)
    {
      cout<<"element before: "<<array[index]<<endl;
      //sort the array with a swap function
      swap(array[index],array[minimum(index, array)]);
      cout<<"element after: "<<array[index]<<endl;
    }
}

int minimum(int position, char array[])
{
  //save position
  int min_index = position;

  //traverse rest of the array and swap if ncessary
  for( int i = position + 1; array[i] != '\0'; i++)
    {
      if((array[i]) < (array[min_index]))
	{
	  min_index = i;	 
	}
    }
  //no smaller value detected after min_index, so return
  return min_index;

}

 void swap(char& first, char& second)
 {
   int temp = (first);
   first =(second);
   second =(temp);
 }
