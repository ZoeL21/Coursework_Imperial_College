#ifndef MULTITAP_H
#define MULTITAP_H

int encode_character(char ch,char* multitap);
void encode(const char* plaintext,char* multitap);


void clear(char* multitap);

#endif
