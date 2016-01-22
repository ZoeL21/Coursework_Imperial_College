 /******freeing memory************/
  /*delete E.get_ptr_pb()->get_mapvector();
  delete E.get_ptr_pb()->get_map();
  delete E.get_ptr_rf()->get_mapvector();
  delete E.get_ptr_rf()->get_map();
  for(int i = 0; i < nbr_of_rotors; i++){
    delete E.get_v_rotors()->at(i).get_mapvector();
    delete E.get_v_rotors()->at(i).get_notchvector();
  }
  delete E.get_ptr_pb();
  delete E.get_ptr_rf();
  delete E.get_v_rotors();*/
  /********************/

















/*//check if input file contains any invalid characters
  int check_content;
  //get size of config data
  while(true){
    in.get(check_content);
    if(in.eof()){
         break;
       }
    if(!isdigit(check_content) || !isspace(temp)){
      return NON_NUMERIC_CHARACTER;
      cout<<"NON_NUMERIC_CHARACTER"<<endl;
    }
  }

  //get size of config data and check if input is in range
  int check_rangeandsize;
  while(true){
  in >> check_rangeandsize;
      if(in.eof()){
        break;
      }
      //check if integer is out of range
      if(check_rangeandsize > 25 || check_rangeandsize < 0){
        return INVALID_INDEX;
        cout<<"INVALID_INDEX"<<endl;
      }
      //increase size counter
      size_config++;
  }

  //check if size_config is even
  if((size_config % 2) != 0){
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    cout<<"INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS"<<endl;
  }

  //close and reopen input stream
  in.close();
  in.open(data);
  if(in.fail()){
    return ERROR_OPENING_CONFIGURATION_FILE;
    cout<<"ERROR_OPENING_CONFIGURATION_FILE"<<endl;
  }

  //create array config
  config = new int[size_config];

 //initialize config_array
  for(int i = 0; i < size_config; i++){
  config[i] = 0;
  }

  //read data from input stream
  for(int i = 0; i < (size_config); i++){
  in >> config[i];
  }

  //close in stream
  in.close();
*/                                                                               |
/*read configuration into map_data array and                                     |
  check for configuration errors*/                                                 |
/*for(int i = 0; i < size_config; i++){                                          |
    for(int j = 0; j < size_config; j++){                                          |
       if(config[i] == config[j] && (i != j)){                                     |
          return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;                               |
          cout<<"IMPOSSIBLE_PLUGBOARD_CONFIGURATION"<<endl;                        |
        }                                                                          |
    }                                                                              |
  }                                                                                |
   //else everything must be ok                                                    |
   return NO_ERROR; */                                                             |
                                  
  /*  ifstream in;
  in.open(data);
  if(in.fail()){
    cout<<"ERROR_OPENING_CONFIGURATION_FILE"<<endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  }
  
  int temp;
  //get size of rotor_array data
  while(true){
      in >> temp;
      if(in.eof()){
	break;
      }
      size_alldata_rotor++;
    }

  //check that file is not bigger than 52 integers
  if(size_alldata_rotor > 52)
    {
      cout<<"INVALID_ROTOR_MAPPING"<<endl;
      return INVALID_ROTOR_MAPPING;
    }

  in.close();
  in.open(data);
   if(in.fail()){
     cout<<"second opening failed."<<endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  }

  //read into array rotor_array
  rotor_array = new int[26];

  //initialize
  for(int i = 0; i < (26); i++){
      rotor_array[i] = 0;
  }
  

  //read data from input stream
  for(int i = 0; i < (26); i++){
    int temp = 0;
    in >> temp;
    rotor_array[i] = temp;
    //cout<< rotor_array[i] << " ";
  }
  cout << endl;
  
  //calculate size of remaining data (notchdata)
  size_notchdata = size_alldata_rotor - 26;
  if(size_notchdata == 0){
    notches = NULL;
    cout<<"no notches"<<endl;
  }
  else{
     //allocate memory to pointer notches
     notches = new int[size_notchdata];
     for(int i = 0; i < (size_notchdata); i++){
     in >> notches[i];
  }
  }

  //check if data is correct
  //check for no repetition
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 26; j++){
 
      if(rotor_array[i] == rotor_array[j] && (i != j)){
	cout<<"repetition"<<endl;
	  return INVALID_ROTOR_MAPPING ;
        }      
    }
      //check if numbers are out of range
      if(rotor_array[i] < 0 || rotor_array[i] > 25){
	cout<<"numbers out of range"<<endl;
	return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
      }
      //check if number is other than digit CHECK MORE!!!!!!!!!!!!!!!!!!!!!!!!!!
      if(isalpha(rotor_array[i])){
	cout<<"not a digit"<<endl;
	return NON_NUMERIC_CHARACTER;
      }  
  }
      
   in.close();
   //else everything must be ok
   return 0;*/   
