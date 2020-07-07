#include "morse.h"

const String commands[] = {			"load_cmf_and_print_text",
									"load_cmf_and_save_text",
									"load_text_and_print_cmf",
									"load_text_and_save_cmf",
									"translate_text_and_print",
									"translate_cmf_and_print",
									"print_format_name",
									"quit:" };
const String morseLettersArr[] = {	"* ---",					// A
									"--- * * *",				// B
									"--- * --- *",				// C
									"--- * *",					// D
									"*",						// E
									"* * --- *",				// F
									"--- --- *",				// G
									"* * * *",					// H
									"* *",						// I
									"* --- --- ---",			// J
									"--- * ---",				// K
									"* --- * *",				// L
									"--- ---",					// M
									"--- *",					// N
									"--- --- ---",				// O
									"* --- --- *",				// P
									"--- --- * ---",			// Q
									"* --- *",					// R
									"* * *",					// S
									"---",						// T
									"* * ---",					// U
									"* * * ---",				// V
									"* --- ---",				// W
									"--- * * ---",				// X
									"--- * --- ---",			// Y
									"--- --- * *" };			// Z
const String morseDigitsArr[] = { "--- --- --- --- ---",		// 0
									"* --- --- --- ---",		// 1
									"* * --- --- ---",			// 2
									"* * * --- ---",			// 3
									"* * * * ---",				// 4
									"* * * * *",				// 5
									"--- * * * *",				// 6
									"--- --- * * *",			// 7
									"--- --- --- * *",			// 8
									"--- --- --- --- *" };		// 9

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
	printf("\t-   * "_GREEN"load_text_and_print"_END" file_name.txt                        -\n");
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

int check_command(String  sdtin_line, int * argc, char ** argv)
{
	int i = 0, j = 0, choise = -1;
	String token;

	// recieve first word - command
	token = strtok(sdtin_line, " ");

	/* save name of command */
	argv[i] = (String )malloc((strlen(token) + 1) * sizeof(char));
	strcpy(argv[i], token);

	/* search command */
	for (j = 0; j < NUM_OF_COMM && choise == -1; ++j)
	{
		if (!strcmp(argv[i], commands[j]))
		{
			choise = j;
		}
	}

	++i;

	if (choise == 4 || choise == 5)
	{
		// recieve the whole string
		token = strtok(NULL, "\0");

		argv[i] = (String)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(argv[i], token);
	}
	else
	{
		// recieve next word
		token = strtok(NULL, " ");

		while (token != NULL && i <= MAX_ARGS_SIZE)
		{
			argv[i] = (String)malloc((strlen(token) + 1) * sizeof(char));
			strcpy(argv[i], token);
			token = strtok(NULL, " ");
			++i;
		}
	}
	
	*argc = i;

	return (choise);
}

void free_memory(int argc, char ** argv)
{
	int i;

	for (i = 0; i < argc; ++i)
	{
		free(argv[i]);
	}

	free(argv);
}

FILE * open_file_for_read(String filename)
{
	FILE * result = NULL;

	result = fopen(filename, "r");

	return (result);
}

FILE *  open_file_for_write(String filename)
{
	FILE * result = NULL;

	result = fopen(filename, "w");

	return (result);
}

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

// TODOOOOOOOOO!!!!!!
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
			buffer = translate_cmf(buffer, MAX_CMS_LENGTH, cmf_file, tree);
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

int load_text_and_translate_cmf_and_print(int argc, char ** argv)
{
	FILE * txt_file = NULL;
	int result = FAILURE;
	String buffer = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));

	if (argc == 2)
	{
		txt_file = open_file_for_read(argv[1]);

		if (txt_file)
		{
			while (!feof(txt_file))
			{
				fgets(buffer, MAX_LENGTH, txt_file);
				printf("%s", from_txt_to_cmf_line(buffer));
			}

			result = SUCCESS;
			fclose(txt_file);
		}
	}
	else
	{
		printf("You must enter one argument\n");
	}

	return (result);
}

int load_text_and_save_cmf(int argc, char ** argv)
{
	FILE * cmf_file = NULL, * txt_file = NULL;
	int result = FAILURE;
	String buffer = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));

	if (argc == 3)
	{
		txt_file = open_file_for_read(argv[1]);
		cmf_file = open_file_for_write(argv[2]);

		if (txt_file && cmf_file)
		{
			while (!feof(txt_file))
			{
				fgets(buffer, MAX_LENGTH, txt_file);
				fprintf(cmf_file, "%s", from_txt_to_cmf_line(buffer));
			}

			result = SUCCESS;

			fclose(txt_file);
			fclose(cmf_file);
		}
	}
	else
	{
		printf("You must enter one argument\n");
	}

	return (result);
}

String from_txt_to_cmf_line(String str_txt)
{
	String morse_res = (String)malloc(sizeof(char)), temp;
	int result = SUCCESS;

	strcpy(morse_res, "");

	if (*str_txt)
	{
		while (*str_txt && result)
		{
			if (isdigit(*str_txt))
			{
				temp = (String)realloc(morse_res, (strlen(morse_res) + 1) + strlen(morseDigitsArr[(*str_txt) - 48]) + 3);

				if (temp)
				{
					morse_res = temp;
					strcat(morse_res, morseDigitsArr[(*str_txt) - 48]);
					strcat(morse_res, "   ");
				}
				//printf("%s   ", morseDigitsArr[(*str_txt) - 48]);
			}
			else
			{
				if (isupper(*str_txt))
				{
					temp = (String)realloc(morse_res, (strlen(morse_res) + 1) + strlen(morseLettersArr[(*str_txt) - 65]) + 3);

					if (temp)
					{
						morse_res = temp;
						strcat(morse_res, morseLettersArr[(*str_txt) - 65]);
						strcat(morse_res, "   ");
					}
					//printf("%s   ", morseLettersArr[(*str_txt) - 65]);
				}
				else
				{
					if (isspace(*str_txt))
					{
						temp = (String)realloc(morse_res, (strlen(morse_res) + 1) + 4);

						if (temp)
						{
							morse_res = temp;
							strcat(morse_res, "    ");
						}
						//printf("    ");
					}
					else
					{
						printf("\nError writting morse code... Please, check\n");
						result = FAILURE;
					}
				}
			}

			++str_txt;
		}
	}

	return (morse_res);
}

int translate_text_and_print(String str_txt)
{
	int result = SUCCESS;

	printf("%s", from_txt_to_cmf_line(str_txt));

	return (result);
}

// TODOOOOOOOOO!!!!!!
int translate_cmf_and_print(String str_cmf)
{
	int result = FAILURE;

	if (*str_cmf)
	{
		printf("%s", str_cmf);
		result = SUCCESS;
	}

	return (result);
}

void print_format_name(String file_name)
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

void quit(int argc, char ** argv)
{
	free_memory(argc, argv);

	printf("Goodbay!\n");
	exit(SUCCESS);
}

void add_symbol_to_tree(Morsetree * tree, String morse_code, char lat_symbol)
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

Morsetree * fill_tree(Morsetree * tree)
{
	tree = create_morsetree('|');
	add_symbol_to_tree(tree, "*-", 'A');
	add_symbol_to_tree(tree, "-***", 'B');
	add_symbol_to_tree(tree, "-*-*", 'C');
	add_symbol_to_tree(tree, "-**", 'D');
	add_symbol_to_tree(tree, "*", 'E');
	add_symbol_to_tree(tree, "**-*", 'F');
	add_symbol_to_tree(tree, "--*", 'G');
	add_symbol_to_tree(tree, "****", 'H');
	add_symbol_to_tree(tree, "**", 'I');
	add_symbol_to_tree(tree, "*---", 'J');
	add_symbol_to_tree(tree, "-*-", 'K');
	add_symbol_to_tree(tree, "*-**", 'L');
	add_symbol_to_tree(tree, "--", 'M');
	add_symbol_to_tree(tree, "-*", 'N');
	add_symbol_to_tree(tree, "---", 'O');
	add_symbol_to_tree(tree, "*--*", 'P');
	add_symbol_to_tree(tree, "--*-", 'Q');
	add_symbol_to_tree(tree, "*-*", 'R');
	add_symbol_to_tree(tree, "***", 'S');
	add_symbol_to_tree(tree, "-", 'T');
	add_symbol_to_tree(tree, "**-", 'U');
	add_symbol_to_tree(tree, "***-", 'V');
	add_symbol_to_tree(tree, "*--", 'W');
	add_symbol_to_tree(tree, "-**-", 'X');
	add_symbol_to_tree(tree, "-*--", 'Y');
	add_symbol_to_tree(tree, "--**", 'Z');
	add_symbol_to_tree(tree, "-----", '0');
	add_symbol_to_tree(tree, "*----", '1');
	add_symbol_to_tree(tree, "**---", '2');
	add_symbol_to_tree(tree, "***--", '3');
	add_symbol_to_tree(tree, "****-", '4');
	add_symbol_to_tree(tree, "*****", '5');
	add_symbol_to_tree(tree, "-****", '6');
	add_symbol_to_tree(tree, "--***", '7');
	add_symbol_to_tree(tree, "---**", '8');
	add_symbol_to_tree(tree, "----*", '9');

	return (tree);
}

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

int read_line(String buff, int size, FILE *fp)
{
	int result = SUCCESS;
	String tmp;

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

String  translate_cmf(String buffer, int size, FILE * cmf_file, Morsetree * tree)
{
	String line = (String)calloc(MAX_CMS_LENGTH * 10, sizeof(char));
	String word, q1;
	char *q2 = (String)calloc(20, sizeof(char));
	int i = 0;

	while (read_line(line, size, cmf_file))
	{
		// split line into words
		for (q1 = line; (word = string_cutter(q1, WORD_DEVIDER)) != NULL; q1 = NULL)
		{
			word_from_cmf_to_txt(word, tree);		
		}
		buffer[i++] = '\n'; // ascii line feed after each line

	}

	buffer[i] = '\0';
	free(line);

	return (buffer);
}

String string_cutter(String input, String delimiter)
{
	static String string;
	if (input != NULL)
		string = input;

	if (string == NULL)
		return string;

	String end = strstr(string, delimiter);
	if (end == NULL)
	{
		String temp = string;
		string = NULL;
		return temp;
	}

	String temp = string;

	*end = '\0';
	string = end + strlen(delimiter);
	return temp;
}

void word_from_cmf_to_txt(char * word, Morsetree * tree)
{
	char letter[22] = "\0";
	char *p = NULL;
	int i = 0;

	p = word;

	while (*p)
	{
		while (*p == ' ')
			p++;

		if (*p == '*' || *p == '-')
		{
			letter[i++] = *p;
			letter[i] = '\0';
			p++;
		}

		if (*p == ' ')
		{
			letter[i++] = *p;
			letter[i] = '\0';
			p++;

			if (*p == ' ')
			{
				letter[i - 1] = '\0';
				printf("%c", read_cmc(tree, letter));
				i = 0;
			}
		}
	}
	printf("%c", read_cmc(tree, letter));
	printf("%c", ' ');
}

char read_cmc(Morsetree *tree, String morse)
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