#ifndef PIG_H
#define PIG_H

#include <fstream>
#include <iostream>

using namespace std;

int findFirstVowel(const char* word);

void translateWord(const char* english,char* translated);

void translateStream(ifstream& in, ostream& out);

#endif
