#include "morse.h"

const String commands[8] = { "load_cmf_and_print_text",
								"load_cmf_and_save_text",
								"load_text_and_print_cmf",
								"load_text_and_save_cmf",
								"translate_text_and_print",
								"translate_cmf_and_print",
								"print_format_name",
								"quit:" };
const String morseLettersArr[] = { "* ---",
							"--- * * *",
							"--- * --- *",
							"--- * *",
							"*",
							"* * --- *",
							"--- --- *",
							"* * * *",
							"* *",
							"* --- --- ---",
							"--- * ---",
							"* --- * *",
							"--- ---",
							"--- *",
							"--- --- ---",
							"* --- --- *",
							"--- --- * ---",
							"* --- *",
							"* * *",
							"---",
							"* * ---",
							"* * * ---",
							"* --- ---",
							"--- * * ---",
							"--- * --- ---",
							"--- --- * *" };
const String morseDigitsArr[] = { "* --- --- --- ---",
							"* * --- --- ---",
							"* * * --- ---",
							"* * * * ---",
							"* * * * *",
							"--- * * * *",
							"--- --- * * *",
							"--- --- --- * *",
							"--- --- --- --- *",
							"--- --- --- --- ---" };

// done
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

// done
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

// done
void free_memory(int argc, char ** argv)
{
	int i;

	for (i = 0; i < argc; ++i)
	{
		free(argv[i]);
	}

	free(argv);
}

// done
FILE * open_file_for_read(char * filename)
{
	FILE * result = NULL;

	result = fopen(filename, "r");

	return (result);
}

// done
FILE *  open_file_for_write(char * filename)
{
	FILE * result = NULL;

	result = fopen(filename, "w");

	return (result);
}

// done
int load_cmf_and_print_text(int argc, char ** argv, Morsetree * tree)
{
	FILE * cmf_file = NULL;
	int result = FAILURE;
	String buffer = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));
	
	if (argc == 2)
	{
		if (cmf_file = open_file_for_read(argv[1]))
		{
			translate_cmf(buffer, MAX_CMS_LENGTH, cmf_file, tree);
			printf("%s", buffer);
			fclose(cmf_file);
		}

		result = SUCCESS;
	}
	else
	{
		printf("You must enter one argument\n");
	}
	
	free(buffer);

	return (result);
}

// done
int load_cmf_and_save_text(int argc, char ** argv, Morsetree * tree)
{
	FILE * cmf_file = NULL, *txt_file = NULL;
	int result = FAILURE;
	String buffer = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));

	if (argc == 3)
	{
		cmf_file = open_file_for_read(argv[1]);
		txt_file = open_file_for_write(argv[2]);

		if (cmf_file)
		{
			translate_cmf(buffer, MAX_CMS_LENGTH, cmf_file, tree);
			fprintf(txt_file, "%s", buffer);
			result = SUCCESS;
			fclose(cmf_file);
			fclose(txt_file);
		}
	}
	else
	{
		printf("You must enter two arguments\n");
	}

	return (result);
}

// TODO, WIP by tamir
int load_text_and_print_cmf(int argc, char ** argv)
{
	FILE * cmf_file = NULL;
	int result = FAILURE;
	String buffer = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));

	if (argc == 2)
	{
		cmf_file = open_file_for_read(argv[1]);

		if (cmf_file)
		{
			/* 
				TODO 
			*/

			result = SUCCESS;
			fclose(cmf_file);
		}
	}
	else
	{
		printf("You must enter one argument\n");
	}

	return (result);
}

// TODO, WIP by tamir
int load_text_and_save_cmf(int argc, char ** argv)
{
	int result = SUCCESS;

	return (result);
}

// TODO
int translate_text_and_print(char * str_txt)
{
	int result = SUCCESS;

	return (result);
}

// TODO, Depricated
int print_cmf(char * str_cmf)
{
	int result = FAILURE;

	if (*str_cmf)
	{
		printf("%s", str_cmf);
		result = SUCCESS;
	}

	return (result);
}

// done
void print_format_name(char * file_name)
{
	if (file_name != NULL)
	{
		if (strstr(file_name, ".cmf"))
		{
			printf("File format: \"cmf\" code morse\n");
		}
		else
		{
			if (strstr(file_name, ".txt"))
			{
				printf("File format: \"txt\" text\n");
			}
			else
			{
				printf("File format not valid\n");
			}
		}
	}
	else
	{
		printf("You must enter name of file\n");
	}
}

// done
void quit(int argc, char ** argv)
{
	free_memory(argc, argv);

	printf("Goodbay!\n");
	exit(SUCCESS);
}

// done
void add_symbol_to_tree(Morsetree * tree, char * morse_code, char lat_symbol)
{
	Morsetree * tmp_tree;
	int i, len;

	tmp_tree = tree;
	len = strlen(morse_code);

	for (i = 0; i < len; i++)
	{
		if (morse_code[i] == '*')
		{
			if (tmp_tree->dot == NULL)
			{
				// end of tree
				tmp_tree->dot = create_morsetree('|');
			}

			tmp_tree = tmp_tree->dot;
		}
		else
		{
			if (tmp_tree->dashs == NULL)
			{
				// end of tree
				tmp_tree->dashs = create_morsetree('|');
			}

			tmp_tree = tmp_tree->dashs;
		}
	}

	tmp_tree->symbol = lat_symbol;
}

// done
Morsetree * create_morsetree(char lat_symbol)
{
	Morsetree * tree = NULL;

	if ((tree = (Morsetree *)malloc(sizeof(Morsetree))) != NULL)
	{
		tree->symbol = lat_symbol;
		tree->dot = NULL;
		tree->dashs = NULL;
	}

	return tree;
}

// done
int read_line(char *buff, int size, FILE *fp)
{
	int result = SUCCESS;
	char *tmp;

	buff[0] = '\0';
	buff[size - 1] = '\0';             //mark end of buffer
	

	if (fgets(buff, size, fp) == NULL) 
	{
		*buff = '\0';                   //EOF 
		result = FAILURE;
		return result;
	}
	else {
		/* remove newline */
		if ((tmp = strrchr(buff, '\n')) != NULL) 
		{
			*tmp = '\0';
		}
	}
	return result;
}

// PROBLEM
char * string_cutter(char *input, char *delimiter) 
{
	static char *string;
	if (input != NULL)
		string = input;

	if (string == NULL)
		return string;

	char *end = strstr(string, delimiter);
	if (end == NULL) 
	{
		char *temp = string;
		string = NULL;
		return temp;
	}

	// TODO ..........this is problem.........
	char *temp = string;

	*end = '\0';
	string = end + strlen(delimiter);
	return temp;
}

// done
char * translate_cmf(String buffer, int size, FILE * cmf_file, Morsetree * tree)
{
	String line = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));
	char *word, *q1, *letter, *q2;
	int i = 0;

	while (read_line(line, size, cmf_file))
	{
		// split line into words
		for (q1 = line; (word = string_cutter(q1, WORD_DEVIDER)) != NULL; q1 = NULL)
		{

			// split the word into letters
			for (q2 = word; (letter = string_cutter(q2, LETTER_DEVIDER)) != NULL; q2 = NULL)
			{
				// decode the Morse code letter and display it

				buffer[i++] = read_cmc(tree, letter);
			}
			buffer[i++] = ' ';
			
		}
		buffer[i++] = '\n'; // ascii line feed after each line

	}

	buffer[i] = '\0';
	free(line);

	return (buffer);
}

//Created by tamir
//Not tested
char * translate_txt(String buffer, int size, FILE * cmf_file, String morseLettersArr, String morseDigitsArr)
{
	String line = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));
	char  * lineIterr;
	int bufferIterr = 0;

	while (!feof(cmf_file))
	{
		fgets(line, MAX_CMS_LENGTH, cmf_file);
		lineIterr = line;

		while (lineIterr != '\0')
		{

			writeMorseChar(buffer, &bufferIterr, lineIterr);
			lineIterr++;
		}	
	}

	free(line);
	return(buffer);
}

// TODO
void addStrToStr(String buffer, char * deliver)
{
	/*
		TODO
	*/
}

// TODO
void writeMorseChar(String buffer, int * bufferIterr, char * morseChar)
{
	if (IS_DIGIT(*bufferIterr))
	{
		//addStrToStr(buffer, morseChar);
	}
	else if (IS_LETTER(*morseChar))
	{
		//addStrToStr(buffer, XXX);
	}
	else if(IS_SPACE(*morseChar))
	{
		addStrToStr(buffer, WORD_DEVIDER);
	}

	addStrToStr(buffer, LETTER_DEVIDER);
	bufferIterr += strlen(LETTER_DEVIDER);
}

// done
char read_cmc(Morsetree *tree, char *morse)
{
	Morsetree * curr = tree;
	char symbol;

	while (*morse)
	{
		if (*morse == '*')
		{
			if (*(++morse) == ' ')
			{
				morse++;
			}

			curr = curr->dot;
		}
		else
		{
			if (*morse == '-' && *(++morse) == '-' && *(++morse) == '-')
			{
				if (*(++morse) == ' ')
				{
					morse++;
				}

				curr = curr->dashs;
			}
		}
	}

	symbol = curr->symbol;

	return (symbol);
}
