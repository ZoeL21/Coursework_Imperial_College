#ifndef MULTITAP_H
#define MULTITAP_H

int encode_character(char ch,char* multitap);
void encode(const char* plaintext,char* multitap);
void append_to(int number,int length,int count,char* multitap);
void encode_recursive(const char* plaintext,int count,char* multitap,bool up_case);

void clear(char* multitap);

#endif
