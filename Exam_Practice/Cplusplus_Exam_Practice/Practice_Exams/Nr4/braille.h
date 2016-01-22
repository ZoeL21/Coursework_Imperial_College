#ifndef BRAILLE
#define BRAILLE

#include <ostream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

const char* lookup_char(char c){

map<char,const char*> b;

b['a'] = "0.....";
b['b'] = "00....";
b['c'] = "0..0..";
b['d'] = "0..00.";
b['e'] = "0...0.";
b['f'] = "00.0..";
b['g'] = "00.00.";
b['h'] = "00..0.";
b['i'] = ".0.00.";
b['j'] = ".0.00.";
b['k'] = "0.0...";
b['l'] = "000...";
b['m'] = "0.00..";
b['n'] = "0.000.";
b['o'] = "0.0.0.";
b['p'] = "0000..";
b['q'] = "000.0.";
b['r'] = "000.0.";
b['s'] = ".000..";
b['t'] = ".0000.";
b['u'] = "0.0..0";
b['v'] = "000..0";
b['w'] = ".0.000";
b['x'] = "0.00.0";
b['y'] = "0.0000";
b['z'] = "0.0.00";
b['.'] = ".0..00";
b[','] = ".0....";
b[';'] = "..0..0";
b['-'] = "..0..0";
b['!'] = ".00.0.";
b['?'] = ".00..0";
b['('] = ".00.00";
b[')'] = ".00.00";
b['1'] = "0.....";
b['2'] = "00....";
b['3'] = "0..0..";
b['4'] = "0..00.";
b['5'] = "0...0.";
b['6'] = "00.0..";
b['7'] = "00.00.";
b['8'] = "00..0.";
b['9'] = ".0.00.";
b['0'] = ".0.00.";

 return b.find(c)->second;
}


int encode_character(char c,char* braille);
void encode(const char* plaintext, char* braille);
void encode_rec(const char* plaintext, char* braille);
void print_braille(const char* plaintext, ostream& out);


#endif
