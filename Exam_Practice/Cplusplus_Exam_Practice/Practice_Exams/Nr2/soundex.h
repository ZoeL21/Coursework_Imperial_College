#ifndef SOUNDEX_H
#define SOUNDEX_H

void encode(const char* surname, char* soundex);
bool compare(const char* str1, const char* str2);
int count(const char* surname, char* sentence);
int count_rec(const char* surname, char* sentence,int count);
#endif
