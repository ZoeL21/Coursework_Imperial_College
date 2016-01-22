#ifndef WORDS
#define WORDS

#include <vector>
#include <cstdio>

using namespace std;

typedef struct wordinfo{
  int length;
  int amount;
wordinfo(int _length, int _amount):length(_length),amount(_amount){}
}wordinfo;

void read_text(FILE* file,vector<wordinfo>& words);

#endif
