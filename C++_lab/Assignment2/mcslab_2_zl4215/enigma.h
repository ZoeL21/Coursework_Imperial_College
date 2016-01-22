#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


//class declarations

/*****PLUGBOARD CLASS*****/
class Plugboard{
 private:
  int size_config_data;
  vector<int>* v_map; 
  int* map_pb;  
public:
  //constructor
 Plugboard(){
    size_config_data = 0;
    v_map = NULL;
    map_pb = NULL;
  }
 //access functions
  int get_size_cnfgdata();
  vector<int>* get_mapvector();
  int* get_map();
  //other functions
  /*function to read data from a configuration
    file and check for the data's validity. Data is 
    saved inside vector pointed to by v_map.
    The function returns the error code according to 
    specifications*/
  int read_data(char* data);
  /*function creating a mapping system for the 
    plugboard using a vector*/
  void map_data();
  /*function which maps a letter using the v_map*/
  int map_letter(const int letter);
  //destructor
  ~Plugboard(){
    if(map_pb != NULL){
      delete [] map_pb;
    }
  };
};
/*****END OF CLASS DECLARATION*****/

/*****REFLECTOR CLASS*****/
class Reflector{
private:
  int size_config_data;
  vector<int>* v_map;
  int* map_rf;
public: 
  //constructor
   Reflector(){
      size_config_data = 0;
      v_map = NULL;      
      map_rf = NULL;
      }
    //access functions
    int get_size_cnfgdata();
    vector<int>* get_mapvector();
    int* get_map();
    //other functions
    /*function to read data from a configuration
      file and check for the data's validity. Data is 
      saved inside vector pointed to by v_map.
      The function returns the error code according to 
      specifications*/
    int read_data(char* data);
    /*function creating a mapping system for the 
      plugboard using a vector*/
    void map_data();
    /*function which maps a letter using the v_map*/
    int map_letter(const int letter);
    //destructor
    ~Reflector(){
      if(map_rf != NULL){
	delete [] map_rf;
      }
    };
  };
/*****END OF CLASS DECLARATION*****/

/*****ROTOR CLASS*****/
class Rotors{
 private:
  int size_notchdata;
  bool notchstat;
  int position;
  vector<int>* map_rot;
  vector<int>* v_notch;
 public: 
  Rotors(){
    position = 0;  
    size_notchdata = 0;  
    notchstat = false;
    map_rot = NULL;
    v_notch = NULL;
  }
  //access functions
  int get_position();
  void set_position(int pos);
  bool get_notchstat();
  vector<int>* get_mapvector();
  vector<int>* get_notchvector();
  //other functions
  /*function to read data from a configuration
    file and check for the data's validity. Data is
    saved and mapped using vector pointed to by map_rot.
    The function returns the error code according to 
    specifications*/
  int read_data(char* data); 
  /*function which rotates the content of the array
    pointed to by map_rot*/ 
  void rotate();
  /*overloaded function of rotate which rotates the rotor
    to the initial position (rotating the content of the array
    (position) times*/
  void rotate(const int position);
  /*function to check if a notch has been hit after rotation
    and which sets the notchstat attribute of 'Rotors' accordingly*/
  void set_notchstat();
  /*function which resets the notchstat attribute to false*/
  void reset_notchstat();
  /*function which enquires the notchstat of the previous rotor
    in order to know if it has to rotate before encrypting*/
  void isnotchset(Rotors prev_rotor); 
  /*function which maps the letter forward*/
  int map_letter_forward(const int letter);
  /*function which maps the letter backwards (after it has passed 
    through the reflector)*/
  int map_letter_backward(const int letter);
  //destructor
  ~Rotors(){
    if(map_rot != NULL){
      map_rot->clear();
      
    }
    if(v_notch != NULL){
      v_notch->clear();
     
    }
  };
};
/*****END OF CLASS DECLARATION*****/


/****ENIGMA CLASS****/
class Enigma{
 private:
  unsigned int nbr_of_rotors;
  vector<Rotors>* v_rotors;
  Reflector* ptr_rf;
  Plugboard* ptr_pb;
 public:
  //constructor
  Enigma(){
    nbr_of_rotors = 0;
    v_rotors = NULL;
    ptr_rf = NULL;
    ptr_pb = NULL;
  }
  //access functions
  int get_nbr_of_rotors();
  Plugboard* get_ptr_pb();
  Reflector* get_ptr_rf();  
  vector<Rotors>* get_v_rotors();
  //other functions
  /*function which creates a Plugbaord, reads the mapping data from 
    the corresponding configuration file and returns according
    to the error specifications (0 if Plugboard was successfully 
    created*/
  int create_Plugboard(char* data);
    /*function which creates a Reflector, reads the mapping data from 
    the corresponding configuration file and returns according
    to the error specifications (0 if Reflector was successfully 
    created*/
  int create_Reflector(char* data);
    /*function which creates the Rotors, reads the mapping data and 
    the initial positions from the corresponding configuration files,  
    and returns according to the error specifications (0 if the Rotors 
    were successfully created*/
  int create_Rotors(char** data, int argc);
  //destructor
  ~Enigma(){
    if(ptr_pb != NULL){
      delete ptr_pb;
    }
    if(ptr_rf != NULL){
      delete ptr_rf;
    }
    if(v_rotors != NULL){
      delete v_rotors;
    }
  };
  
};
/*****END OF CLASS DECLARATION******/


//function declarations

/*function which creates the amount of rotors given by the command line
  arguments and places them inside a vector*/
int setup_rotors(const int argc, vector<Rotors>* &v_rotors, char** argv);
/*function which reads the initial starting positins of each rotor into the
  'position' attribute of the Rotor object from a configuration file and 
  checks for the validity of the data.The function 
  returns the error code according to specifications*/
int read_init_positions(char* data,vector<Rotors>* v_rotors, unsigned int nbr_of_rotors);
/*function which displays each rotors data*/
int get_input(int& letter);
/*function which converts the encrypted letter of type int(0-25 alphabet)
  to its corresponding char*/
char output(int letter_encrypted);
/*function which encrypts a letter using Enigma and its components*/
int encryption(int letter,Enigma* E_ptr);
/*function which rotates each rotor to its initial position*/
void rot_to_init_pos(vector<Rotors>* v_rotors, unsigned int nbr_of_rotors);
