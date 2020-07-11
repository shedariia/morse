#ifndef _MORSE_H
#define _MORSE_H

#include <stdio.h>				/* fopen(), printf(), ... */
#include <string.h>				/* strcmp(), strlen(), ... */
#include <stdlib.h>				/* malloc(), free(), ...*/
#include <ctype.h>				/* isdigit(), isspace(), ... */

#define SUCCESS 1				/* exit without errors */
#define FAILURE 0				/* exit with error */
#define MAX_LENGTH 255			/* max length of string */
#define MAX_CMS_LENGTH 10000	/* max length of morse code string in file */
#define MAX_CMS_LINE 500		/* max length of morse line in morse code */
#define TRANSLATE_BUFFER 5000	/* max length of text that program can translate */
#define MAX_ARGS_SIZE 2			/* max number of arguments */
#define NUM_OF_COMM 8			/* number of commands */
#define WORD_DEVIDER "       "	/* seven spaces between words */
#define LETTER_DEVIDER "   "	/* three spaces between words */
#define MORSE_DIGIT_OFFSET 48	/* help arrive first cell in digit array */
#define MORSE_LETTER_OFFSET 65	/* help arrive first cell in letters array */

#define _GREEN "\033[1;32m"		/* green color in stdout */
#define _END "\033[0m"			/* default color in stdout */

#pragma warning (disable: 4996)	/* hide warning for fopen(), fcolse(), ... */

typedef char * String;

typedef struct morsetree 
{
	char symbol;
	struct morsetree * dashs;
	struct morsetree * dot;
} Morsetree;

/* print_menu
-------------------------------------------------------------------------------
Description: prints all commands to stdout

Arguments: none

Return value: none */
void print_menu(void);

/* check_command
-------------------------------------------------------------------------------
Description: check command validation

Arguments:
	• sdtin_line	- full string from user
	• argc			- number of substring
	• argv			- array with value of substrings

Return value: number of command or -1 if command not found */
int check_command(String  sdtin_line, int * argc, char ** argv);

/* free_memory
-------------------------------------------------------------------------------
Description: free allocated memory

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings

Return value: none */
void free_memory(int argc, char ** argv);

/* open_file_for_read
-------------------------------------------------------------------------------
Description: opens file for reading

Arguments:
	• file_for_read	- file's name

Return value: pointer to openned file for reading */
FILE * open_file_for_read(String  file_for_read);

/* open_file_for_write
-------------------------------------------------------------------------------
Description: opens file for writing

Arguments:
	• file_for_write	- file's name

Return value: pointer to openned file for writing */
FILE * open_file_for_write(String  file_for_write);

/* load_cmf_and_print_text
-------------------------------------------------------------------------------
Description: translate file from code morse and print results to stdout

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings
	• tree	- morse tree

Return value: 0 - success, 1 - fail*/
int load_cmf_and_print_text(int argc, char ** argv, Morsetree * tree);

/* load_cmf_and_save_text
-------------------------------------------------------------------------------
Description: translate file from code morse and save results to another file

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings
	• tree	- morse tree

Return value: 0 - success, 1 - fail*/
int load_cmf_and_save_text(int argc, char ** argv, Morsetree * tree);

/* load_text_and_translate_cmf_and_print
-------------------------------------------------------------------------------
Description: translate file to code morse and print results to stdout

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings

Return value: 0 - success, 1 - fail*/
int load_text_and_translate_cmf_and_print(int argc, char ** argv);

/* load_text_and_save_cmf
-------------------------------------------------------------------------------
Description: translate file to code morse and save results to another file

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings

Return value: 0 - success, 1 - fail*/
int load_text_and_save_cmf(int argc, char ** argv);

/* translate_text_and_print
-------------------------------------------------------------------------------
Description: translate string from stdin to code morse

Arguments:
	• str_txt	- string with simple text

Return value: 0 - success, 1 - fail*/
int translate_text_and_print(String  str_txt);

/* translate_cmf_and_print
-------------------------------------------------------------------------------
Description: translate string from stdin from code morse

Arguments:
	• str_cmf	- string with code morse

Return value: 0 - success, 1 - fail*/
int translate_cmf_and_print(String  str_cmf, Morsetree * tree);

/* print_format_name
-------------------------------------------------------------------------------
Description: prints format of file to stdout

Arguments:
	• str_cmf	- line of code morse
	• tree	- structer of morse letters
Return value: none */
void print_format_name(String  file_name);

/* quit
-------------------------------------------------------------------------------
Description: close the programm without errors

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings

Return value: none */
void quit(int argc, char ** argv);

/* create_morsetree
-------------------------------------------------------------------------------
Description: add first symbol to tree structure

Arguments:
	• lat_symbol	- symbol

Return value: none */
Morsetree * create_morsetree(char lat_symbol);

/* add_symbol_to_tree
-------------------------------------------------------------------------------
Description: add one symbol to morse tree structure

Arguments:

	• tree			- morse tree
	• morse_code	- morse code of symbol
	• lat_symbol	- symbol

Return value: none */
void add_symbol_to_tree(Morsetree * tree, String  morse_code, char lat_symbol);

/* fill_tree
-------------------------------------------------------------------------------
 Description: fill morse tree

 Arguments:
	• tree	- a point Morse tree

 Return value: filled morse tree */
Morsetree * fill_tree(Morsetree * tree);

/* read_line
-------------------------------------------------------------------------------
Description: read one line form input file

Arguments:

	• buff	- buffer to readed string 
	• size	- size of buffer
	• fp	- file stream

Return value: 0 - success, 1 - fail */
int read_line(String  buff, int size, FILE * fp);

/* cut_string
-------------------------------------------------------------------------------
 Description: cut strings before delimeter

 Arguments:
	• input		- a pointer to the input
	• delimiter	- a pointer to the delimetr string

 Return value: returns pointer to string after cutting */
String cut_string(String input, String delimiter);

/* clean_string
-------------------------------------------------------------------------------
 Description: cut strings before delimeter

 Arguments:
	• str		- a pointer to the string

 Return value: non */
void clean_string(String str);

/* word_from_cmf_to_txt
-------------------------------------------------------------------------------
 Description: translate word of morse code to text

 Arguments:
	• translate	- buffer for traslated word
	• mcf_word	- word of morse code
	• tree		- morse tree

 Return value: none */
void word_from_cmf_to_txt(String translate, String mcf_word, Morsetree * tree);

/* translate_cmf
-------------------------------------------------------------------------------
 Description: taranslate morse code from file to text

 Arguments:
	• translate		- a pointer to buffer with text
	• cmf-cmf_line	- a pointer to buffer with morse line
	• tree			- a pointer Morse tree

 Return value: returns Pointer to buffer with text */
String translate_cmf(String translate, String cmf_line, Morsetree * tree);

/* read_cmc
-------------------------------------------------------------------------------
 Description: translate morse character to text

 Arguments:
	• morse	- a pointer to String morse character representation
	• tree	- a point Morse tree

 Return value: returns character text */
char read_cmc(Morsetree * tree, String  morse);

/* fill_tree
-------------------------------------------------------------------------------
 Description: translate text to morse code

 Arguments:
	• str_txt	- string with text

 Return value: line after translation */
String from_txt_to_cmf_line(String str_txt);

/* is_code_morse
-------------------------------------------------------------------------------
 Description: check if string is code morse

 Arguments:
	• str	- string with text

 Return value: 1 - is morse code, 0 - is not morse code */
int is_code_morse(String str);

/* initialization of old standart function */
String gets(String str);

#endif // _MORSE_H