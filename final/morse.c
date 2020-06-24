#include "morse.h"

const char * commands[8] = { "load_cmf_and_print_text",
								"load_cmf_and_save_text",
								"load_text_and_print_cmf",
								"load_text_and_save_cmf",
								"translate_text_and_print",
								"translate_cmf_and_print",
								"print_format_name",
								"quit:" };

void print_menu(void)
{
	printf("\t--------------------------------------------------------------------\n");
	printf("\t-                   Welcome to Morse translator!                   -\n");
	printf("\t-                          You may to do:                          -\n");
	printf("\t--------------------------------------------------------------------\n");
	printf("\t-   * "_GREEN"load_cmf_and_print_text"_END" file_name.cmf                        -\n");
	printf("\t-     Translate morse file to text and print results               -\n");
	printf("\t-   * "_GREEN"load_cmf_and_save_text"_END" file_name.cmf file_name.txt           -\n");
	printf("\t-     Translate morse file to text and save results to new file    -\n");
	printf("\t-   * "_GREEN"load_text_and_print_cmf"_END" file_name.txt                        -\n");
	printf("\t-     Translate text file to morse and print results               -\n");
	printf("\t-   * "_GREEN"load_text_and_save_cmf"_END" file_name.txt file_name.cmf           -\n");
	printf("\t-     Translate txt file to morse and save results to new file     -\n");
	printf("\t-   * "_GREEN"translate_text_and_print"_END" txt_string                          -\n");
	printf("\t-     Translate string to morse                                    -\n");
	printf("\t-   * "_GREEN"translate_cmf_and_print"_END" cmf_string                           -\n");
	printf("\t-     Translate string from morse                                  -\n");
	printf("\t-   * "_GREEN"print_format_name"_END" file_name                                  -\n");
	printf("\t-     Print format of file                                         -\n");
	printf("\t-   * "_GREEN"quit:"_END"                                                        -\n");
	printf("\t-     Close the program                                            -\n");
	printf("\t--------------------------------------------------------------------\n");
}

int check_command(char * tmp, int * argc, char ** argv)
{
	int i = 0, choise = -1;
	char *token;

	token = strtok(tmp, " ");

	while (token != NULL && i <= MAX_ARGS_SIZE)
	{
		argv[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(argv[i], token);
		token = strtok(NULL, " ");
		++i;
	}

	*argc = i;

	for (i = 0; i < NUM_OF_COMM; ++i)
	{
		if (!strcmp(argv[0], commands[i]))
		{
			choise = i;
		}
	}

	return (choise);
}

void free_memory(char ** argv)
{
	int i;

	for (i = 0; i <= MAX_ARGS_SIZE; ++i)
	{
		free(argv[i]);
	}

	free(argv);
}

FILE * open_file_for_read(char * filename)
{
	FILE * result = NULL;

	result = fopen(filename, "r");

	return (result);
}

FILE *  open_file_for_write(char * filename)
{
	FILE * result = NULL;

	result = fopen(filename, "w");

	return (result);
}

int load_cmf_and_print_text(int argc, char ** argv)
{
	FILE * cmf_file = NULL;
	int result = SUCCESS;

	cmf_file = open_file_for_read(argv[1]);

	/*
	TODO
	*/

	fclose(cmf_file);

	return (result);
}

int load_cmf_and_save_text(int argc, char ** argv)
{
	FILE * cmf_file = NULL, *txt_file = NULL;
	int result = SUCCESS;

	cmf_file = open_file_for_read(argv[1]);
	txt_file = open_file_for_write(argv[2]);

	/*
	TODO:
	*/

	fclose(cmf_file);
	fclose(txt_file);

	return (result);
}

int load_text_and_print_cmf(int argc, char ** argv)
{
	int result = SUCCESS;

	return (result);
}

int load_text_and_save_cmf(int argc, char ** argv)
{
	int result = SUCCESS;

	return (result);
}

int translate_text_and_print(char * str_txt)
{
	int result = SUCCESS;

	return (result);
}

int translate_cmf_and_print(char * str_cmf)
{
	int result = SUCCESS;

	return (result);
}

void print_format_name(char * file_name)
{

}

void quit(char ** argv)
{
	free_memory(argv);

	printf("Goodbay!\n");
	exit(SUCCESS);
}