#ifndef _MORSE_H
#define _MORSE_H

#include <stdio.h>		/* fopen(), printf(), ... */
#include <string.h>		/* strcmp(), strlen(), ... */
#include <stdlib.h>		/* malloc(), free(), ...*/

#define SUCCESS 1
#define FAILURE 0
#define MAX_LENGTH 255
#define MAX_ARGS_SIZE 2
#define NUM_OF_COMM 8

#define _GREEN "\033[1;32m"
#define _END "\033[0m"

#pragma warning (disable: 4996)

void print_menu(void);
int check_command(char * tmp, int * argc, char ** argv);
void free_memory(char ** argv);
int open_file_for_read(FILE * file_for_read);
int open_file_for_write(FILE * file_for_write);
int load_cmf_and_print_text(int argc, char ** argv);
int load_cmf_and_save_text(int argc, char ** argv);
int load_text_and_print_cmf(int argc, char ** argv);
int load_text_and_save_cmf(int argc, char ** argv);
int translate_text_and_print(char * str_txt);
int translate_cmf_and_print(char * str_cmf);
void print_format_name(char * file_name);
void quit(char ** argv);

#endif // _MORSE_H