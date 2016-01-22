#include <iostream>

using namespace std;

//prototypes
int partition(int array[],int beginning,int end);
void quicksort(int array[],int beginning, int end);
void swap(int& one, int& two);
void display_array(int array[], int end);

int main(){
  
  int size;

  cout<<"enter the size of the array to be sorted"<<endl;
  cin>>size;

  int* array = new int[size];

  cout<<"Type in the values of the unsorted array, leaving spaces between the integers"<<endl;

  for(int i = 0; i < size; i++){
    cin>>array[i];
  }

  cout<<"You entered the array: "<<endl;

  for(int i = 0; i < size; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;

  quicksort(array,0,(size - 1));

  //output the sorted array
  cout<<"Your sorted array is: "<<endl;
  for(int i = 0; i < size; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;

  return(0);
}

void quicksort(int array[], int beginning, int end){
  
    if(beginning < end){
      int pivot = partition(array,beginning, end);
      quicksort(array,beginning,(pivot - 1));
      quicksort(array,(pivot + 1), end);
    }     

}

int partition(int array[], int beginning, int end){
  
  int value = array[end];
  int i = beginning;
 
  for(int j = beginning; j < end; j++){
    
    if(array[j] < value){
      if(i != j){
	swap(array[i],array[j]);
      }
	//increase i
      i += 1;
    }
  }

  //swap element at i + 1 with last element
  
  swap(array[i],array[end]);

  return i;
}

void swap(int& one, int& two){
  
  int temp = two;
  two = one;
  one = temp;

}

void display_array(int array[],int end){
  for(int i = 0; i < end; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}
