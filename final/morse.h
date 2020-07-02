#ifndef _MORSE_H
#define _MORSE_H

#include <stdio.h>				/* fopen(), printf(), ... */
#include <string.h>				/* strcmp(), strlen(), ... */
#include <stdlib.h>				/* malloc(), free(), ...*/

#define SUCCESS 1				/* exit without errors */
#define FAILURE 0				/* exit with error */
#define MAX_LENGTH 255			/* max length of string */
#define MAX_CMS_LENGTH 1000		/* max length of morse code string in file */
#define MAX_ARGS_SIZE 2			/* max number of arguments */
#define NUM_OF_COMM 8			/* number of commands */
#define WORD_DEVIDER "       " /* seven spaces between words */
#define LETTER_DEVIDER "   "	/* three spaces between words */

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

//	{'A', "* ---"},
//	{'B', "--- * * *"},
//	{'C', "--- * --- *"},
//	{'D', "--- * *"},
//	{'E', "*"},
//	{'F', "* * --- *"},
//	{'G', "--- --- *"},
//	{'H', "* * * *"},
//	{'I', "* *"},
//	{'J', "* --- --- ---"},
//	{'K', "--- * ---"},
//	{'L', "* --- * *"},
//	{'M', "--- ---"},
//	{'N', "--- *"},
//	{'O', "--- --- ---"},
//	{'P', "* --- --- *"},
//	{'Q', "--- --- * ---"},
//	{'R', "* --- *"},
//	{'S', "* * *"},
//	{'T', "---"},
//	{'U', "* * ---"},
//	{'V', "* * * ---"},
//	{'W', "* --- ---"},
//	{'X', "--- * * ---"},
//	{'Y', "--- * --- ---"},
//	{'Z', "--- --- * *"},
//	{'1', "* --- --- --- ---"},
//	{'2', "* * --- --- ---"},
//	{'3', "* * * --- ---"},
//	{'4', "* * * * ---"},
//	{'5', "* * * * *"},
//	{'6', "--- * * * *"},
//	{'7', "--- --- * * *"},
//	{'8', "--- --- --- * *"},
//	{'9', "--- --- --- --- *"},
//	{'0', "--- --- --- --- ---"}

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
	• tmp	- full string from user
	• argc	- number of substring
	• argv	- array with value of substrings

Return value: number of command or -1 if command not found */
int check_command(char * tmp, int * argc, char ** argv);

/* free_memory
-------------------------------------------------------------------------------
Description: free allocated memory

Arguments:
	• argv	- array with value of substrings

Return value: none */
void free_memory(char ** argv);

/* open_file_for_read
-------------------------------------------------------------------------------
Description: opens file for reading

Arguments:
	• file_for_read	- file's name

Return value: pointer to openned file for reading */
FILE * open_file_for_read(char * file_for_read);

/* open_file_for_write
-------------------------------------------------------------------------------
Description: opens file for writing

Arguments:
	• file_for_write	- file's name

Return value: pointer to openned file for writing */
FILE * open_file_for_write(char * file_for_write);

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

Return value: 0 - success, 1 - fail*/
int load_cmf_and_save_text(int argc, char ** argv);

/* load_text_and_print_cmf
-------------------------------------------------------------------------------
Description: translate file to code morse and print results to stdout

Arguments:
	• argc	- number of substring
	• argv	- array with value of substrings

Return value: 0 - success, 1 - fail*/
int load_text_and_print_cmf(int argc, char ** argv);

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
int translate_text_and_print(char * str_txt);

/* print_cmf
-------------------------------------------------------------------------------
Description: translate string from stdin from code morse

Arguments:
	• str_cmf	- string with code morse

Return value: 0 - success, 1 - fail*/
int print_cmf(char * str_cmf);

/* print_format_name
-------------------------------------------------------------------------------
Description: prints format of file to stdout

Arguments:
	• file_name	- name of file

Return value: none */
void print_format_name(char * file_name);

/* quit
-------------------------------------------------------------------------------
Description: close the programm without errors

Arguments:

	• argv	- array with value of substrings

Return value: none */
void quit(char ** argv);

/* add_symbol_to_tree
-------------------------------------------------------------------------------
Description: add one symbol to morse tree structure

Arguments:

	• tree			- 
	• morse_code	-
	• lat_symbol	-

Return value: none */
void add_symbol_to_tree(Morsetree * tree, char * morse_code, char lat_symbol);

/* create_morsetree
-------------------------------------------------------------------------------
Description: add first symbol to tree structure

Arguments:

	• lat_symbol	-

Return value: none */
Morsetree * create_morsetree(char lat_symbol);

/* read_line
-------------------------------------------------------------------------------
Description: read one line form input file


Arguments:

	• buff	- buffer to readed string 
	• size	- size of buffer
	• fp	- file stream

Return value: 0 - success, 1 - fail*/
int read_line(char * buff, int size, FILE * fp);

/*
*/
char * string_cutter(char * input, char * delimiter);

/*

*/
char * translate_cmf(String buffer, int size, FILE * cmf_file, Morsetree * tree);
/*

*/
char read_cmc(Morsetree * tree, char * morse);

#endif // _MORSE_H