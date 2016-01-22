#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(char *binary);

void binary_to_text(const char* binary,char* text_encoded);
void binary_to_text_rec_helper(const char* binary,char* text_encoded);

void text_to_binary(const char* text,char* binary);

void add_error_correction(const char* data, char* corrected);

int decode(const char* received, char* decoded);



#endif
