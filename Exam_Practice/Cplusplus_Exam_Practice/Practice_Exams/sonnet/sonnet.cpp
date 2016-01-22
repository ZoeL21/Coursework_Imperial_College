#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

#include "sonnet.h"

/* PRE-SUPPLIED HELPER FUNCTIONS START HERE */

/* NOTE: It is much more important to understand the interface to and
   the "black-box" operation of these functions (in terms of inputs and
   outputs) than it is to understand the details of their inner working. */

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int word_number, char *output_word) {
  char *output_start = output_word;
  int words = 0;

  if (word_number < 1) {
    *output_word = '\0';
    return false;
  }
  
  do {
    while (*input_line && !isalnum(*input_line))
      input_line++;

    if (*input_line == '\0')
      break;

    output_word = output_start;
    while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
      *output_word = toupper(*input_line);
      output_word++;
      input_line++;
    }
    *output_word = '\0';

    if (++words == word_number)
      return true;

  } while (*input_line);

  *output_start = '\0';
  return false;
}

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending) {

  // the next rhyming letter to be issued (persists between calls)
  static char next = 'a';
  // the table which maps endings to letters (persists between calls)
  static map<string, char> lookup;

  // providing a way to reset the table between poems
  if (ending == RESET) {
    lookup.clear();
    next = 'a';
    return '\0';
  }

  string end(ending);

  // if the ending doesn't exist, add it, and issue a new letter
  if (lookup.count(end) == 0) {
    lookup[end]=next;
    assert(next <= 'z');
    return next++;
  }

  // otherwise return the letter corresponding to the existing ending
  return lookup[end];
}

/* START WRITING YOUR FUNCTION BODIES HERE */


int count_words(const char* line){

  if(strlen(line) == 0){
    return 0;
  }

  stringstream stream(line);
  string oneWord;

  unsigned int count = 0;
  while(stream >> oneWord){count++;}

  return count;
}


bool find_phonetic_ending(const char* word,char* phonetic_ending){

  //initialize phonetic_ending
  phonetic_ending[0] = '\0';

  //declare and open filestream
  FILE* in = fopen("dictionary.txt","r");
  if(in == NULL){
    cout<<"Error opening file"<<endl;
    exit(1);
  }


  //create a string with spaces around word
  char word_space[50];
  strcpy(word_space,word);
  strcat(word_space," ");
 

  //copy line by line into buffer
  char buffer[100];
  while(fgets(buffer,99,in)){
      
    //search for word in line
    char* loc_word = strstr(buffer,word_space);
    if(loc_word != NULL && *loc_word == buffer[0]){

      //find last vowel	
      char* vowel_loc = NULL;
      char* vowel_temp = NULL;
      
      vowel_loc = strrchr(buffer,'A');
	
      vowel_temp = strrchr(buffer,'E');
      if(vowel_temp > vowel_loc){
	vowel_loc = vowel_temp;
      }
	
      vowel_temp = strrchr(buffer,'I');
      if(vowel_temp > vowel_loc){
	vowel_loc = vowel_temp;
      }
	
      vowel_temp = strrchr(buffer,'O');
      if(vowel_temp > vowel_loc){
	vowel_loc = vowel_temp;
      }
	
      vowel_temp = strrchr(buffer,'U');
      if(vowel_temp > vowel_loc){
	vowel_loc = vowel_temp;
      }
	
      //vowel_loc should now hold the location of the phonetic ending
      //inside the sentence
      strcat(phonetic_ending,vowel_loc);
      return true;
    }
    }

  //otherwise, word has not been located
  cout<<"could not find word: "<<word<<endl;
  strcat(phonetic_ending,"");

  return false;
}

/*
bool is_vowel(char c){
 
  if(c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U'){   
    return true;
  }
  return false;
}

bool is_word(const char* word,ifstream& in){
  
  char c;
  for(int i = 1; word[i] != '\0';i++){
    in.get(c);
    if(word[i] != c){
      return false;
    }
  }
  return true;
} 
*/

  
bool find_rhyme_scheme(const char* filename,char* scheme){

  rhyming_letter(RESET);
  scheme[0] = '\0';

  /*  char c;

  //open file
  ifstream in;
  in.open(filename);
  if(in.fail()){
    cout<<"could not open file"<<endl;
    return false;
  }

  string scheme_s = string();

  //read line by line until end of file is reached
  while(true){
    string line = string();
  
    in.get(c);
    if(in.eof()){
      break;
    }

    //separate line
    while(c != '\n'){
      line = line + c;
      in.get(c);
    }
    const char* line_c = line.c_str();
  */
  FILE* ptr = fopen(filename,"r");
  if(ptr == NULL){
    return false;
  }
  char buffer[100];

  string scheme_s = string();

  while(fgets(buffer,99,ptr)){

    //find amount of words in line
    int word_number = count_words(buffer);

    //get last word
    char output_word[30];
    if(!get_word(buffer,word_number,output_word)){
      cout<<"could not get word"<<endl;
    }

    //find phonetic ending
    char phonetic_ending[20];
    if(!find_phonetic_ending(output_word,phonetic_ending)){
      cout<<"Could not find phonetic ending"<<endl;
    }

    char letter;
    letter = rhyming_letter(phonetic_ending);

    //attach to scheme_s
    scheme_s = scheme_s + letter;
  }

  const char* scheme_c = scheme_s.c_str();
  strcpy(scheme,scheme_c);
  return true;


}    


const char* identify_sonnet(const char* filename){
  
  
  //open file
  ifstream in;
  in.open(filename);
  if(in.fail()){
    cout<<"could not open file"<<endl;    
  }

  char scheme[40];
  if(!find_rhyme_scheme(filename,scheme)){
    return "Error";
  }

  char S[] = "ababcdcdefefgg";
  char P[] = "abbaabbacdcdcd";
  char Sp[] = "ababbcbccdcdee";

  if(!strcmp(S,scheme)){

      return "Shakespearean";
    }
  else if(!strcmp(P,scheme)){
      return "Petrarchian";
    }
  else if(!strcmp(Sp,scheme)){
    return "Spencerian";
  }
  else{
    return "Unknown";
  }

}
    

