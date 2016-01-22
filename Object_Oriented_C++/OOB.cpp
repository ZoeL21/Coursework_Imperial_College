#include <iostream>
#include <string>

class Library {
};

class LibraryUser {
private:
public:
  LibraryUser(string_nme) : name(_name) { };
  bool borrowItem( Item* item);
};
//class Book nherits from class Items (their public 
class Book: public Items {
private: 
  int loanPeriod;
public:
  //constructor for Book calling constructor for Items
  Book(string _title, int _location, int _lp) : Items( _title, _location) {
    loanperiod = _lp;
  }
};

class Periodical : public Items {
private:
  static int loadPeriod;
public:
  Periodical(string _title, int _location) : Items( _title, -location)
  {
  };
};

//declare the static loan period
int Periodical::loanPeriod = 5;

class Items {
protected: 
  string title;
  int location;
  LibraryUser *borrowedBY;
public:
  Items(string _title, int _location) : title( _title), location( _location) {
    borrowedBy = NULL;  
   }
};

int main(){

  Book cppwt("C++ without Tears"
}



//protected means this class and the derived classes can access it, private means, it is only accessibe by this class.
