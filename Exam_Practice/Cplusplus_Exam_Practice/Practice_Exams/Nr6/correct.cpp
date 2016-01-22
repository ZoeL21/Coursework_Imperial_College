#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1)
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */
void text_to_binary(const char* text,char* binary){

  //  cout<<sizeof(binary)<<endl;

  //make sure that binry is large enough
  /*if(sizeof(binary) < (strlen(text) + 1)){
    cout<<"array binary is too small!"<<endl;
    return;
    }*/

  //create a buffer to store the result of every
  //character conversion
  char buffer[9];
  //calling ascii_to_binary for every letter
  for(int i = 0; text[i] != '\0';i++){
    
    ascii_to_binary(text[i],buffer);
    
    //concatenate buffer to binary
    strncat(binary,buffer,9);
  }
}

void binary_to_text_rec_helper(const char* binary,char* text_encoded){
  char first_letter[9];
  strncpy(first_letter,binary,8);
  first_letter[8] = '\0';
  char c = binary_to_ascii(first_letter);
  char conversion[2];
  conversion[0] = c;
  conversion[1] = '\0';
  //concateate
  strcat(text_encoded,conversion);

  if(strlen(binary) >= 8){
  //use a pointer to obtain the rest of the binary string
  const char* ptr = binary;

  //advance pointer to 9th position
  for(int i = 0; i < 8; i++){
    ptr++;
  }
  //cout<<"pinter nw points to: "<<*ptr<<endl;

  //the new pointer delimits the new string
  binary_to_text_rec_helper(ptr,text_encoded);
 }
}


void binary_to_text(const char* binary,char* text_encoded){

  text_encoded[0] = '\0';

  binary_to_text_rec_helper(binary,text_encoded);

}




void add_error_correction(const char* data, char* corrected){

  //initialize corrected
  corrected[0] = '\0';

    //declare pairty
  char c1,c2,c3;

  //calculate the parity parameters
  if((data[0] + data[1] + data[3]) % 2 == 0){
    c1 = '0';
  }
  else{
    c1 = '1';
  }
  if((data[0] + data[2] + data[3]) % 2 == 0){
    c2 = '0';
  }
  else{
    c2 = '1';
  }
  if((data[1] + data[2] + data[3]) % 2 == 0){
    c3 = '0';
  }
  else{
    c3 = '1';
  }

  //add parity paremters to array corrected
 
  string decode = string() + c1 + c2 + data[0] + c3 + data[1] + data[2] + data[3];
  cout<<"string is: "<<decode<<endl;
 
  const char* decoded = decode.c_str();

  strcat(corrected,decoded);
}

int decode(const char* received, char* decoded){
  

  //check input
  if(strlen(received) > 7){
    cout<<"input too long"<<endl;
  }

  //initialize decoded
  decoded[0] = '\0';

  cout<<"received: "<<received<<endl;
  cout<<"received_int: ";
  //change input into numbers
  int received_int[8];
  for(int i = 0; i < 7;i++){
    received_int[i] = received[i] - 48;
    cout<<received_int[i];
  }
  cout<<endl;

  int errors = 0;

  //do parity checks
  char p1,p2,p3;

  if(((received_int[3] + received_int[4] + received_int[5] + received_int[6]) % 2) == 0){
    p1 = '0';
  }
  else{
    p1 = '1';
    errors++;
  }
  if(((received_int[1] + received_int[2] + received_int[5] + received_int[6]) % 2) == 0){
    p2 = '0';
  }
  else{
    p2 = '1';
    errors++;
  }
  if(((received_int[0] + received_int[2] + received_int[4] + received_int[6]) % 2) == 0){
    p3 = '0';
  }
  else{
    p3 = '1';
    errors++;
  }

  string parity = string() + p1 + p2 + p3;
  
  cout<<"parity is: "<<parity<<endl;

  if(errors == 0){

    string result = string() + received[2] + received[4] + received[5] + received[6];
    const char* result_c = result.c_str();

    strcat(decoded, result_c);

    return errors;
  }
  else{
    //find the error
    int value_decimal = (parity[2] - 48) * 1 + (parity[1] - 48) * 2 + (parity[0] - 48) * 4;

    cout<<"decimal value is: "<<value_decimal<<endl;

    if(value_decimal > 7){
      cout<<"error in calculation"<<endl;
      exit(1);
    }

    //copy received_int into modifiable string
    char copy_received[9];
    strncpy(copy_received,received,8);
    copy_received[8] = '\0';

    //swap bit
    int index = value_decimal - 1;
    if(copy_received[index] == '0'){
      copy_received[index] = '1';
    }
    else{
      copy_received[index] = '0';
    }

    string result = string() + copy_received[2] + copy_received[4] + copy_received[5] + copy_received[6];
    const char* result_c = result.c_str();


    strcat(decoded, result_c);
 
    return errors;
  }
}




