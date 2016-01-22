#include "stringsort.h"
#include <iostream>
#include <cstring>

using namespace std;

void display_string(char arraytodisplay[]){

  for(int i = 0;arraytodisplay[i] != '\0';i++){
    cout<<arraytodisplay[i];
  }
  cout<<endl;
}

int find_smaller(int valueindex,char arraytosort[],int length){

  char value = arraytosort[valueindex];
  int return_index = valueindex;

  for(int index = valueindex + 1; index < length; index++){
    if (arraytosort[index] < value){
      cout<<arraytosort[index]<<" comes before "<<value<<endl;
      return_index = index;
      value = arraytosort[index];
    }
  }

  return return_index;
}


void sort_string(char arraytosort[]){

  int length = strlen(arraytosort);
  //traverse string and replace each element
  for(int i = 0; i < length;i++){
    int i_swap = find_smaller(i,arraytosort,length);
    swap(i,i_swap,arraytosort);
    cout<<"string is now: "<<arraytosort<<endl;
  }
}


void swap(int index,int other_index, char arraytosort[]){

  char temp = arraytosort[index];
  arraytosort[index] = arraytosort[other_index];
  arraytosort[other_index] = temp;

}
	 
