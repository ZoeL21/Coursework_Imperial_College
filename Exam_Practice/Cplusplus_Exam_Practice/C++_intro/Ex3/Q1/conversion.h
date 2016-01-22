#ifndef CONVERSION_H
#define CONVERSION_H

void print_preliminary_message();
void  input_table_specifications(int& lower,int& upper,int& step);
void  print_message_echoing_input(int& lower,int& upper,int& step);
void print_table(int& lower,int& upper,int& step);
void print_header();
double celsius_of(int fahr);
double absolute_value_of(int fahr);

#endif
