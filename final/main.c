/* LIBRARIES */
#include "morse.h"	/* check_command(), print_format_name(), ... */

/* MAIN function */
void main(void)
{
	int choise = 0;
	int argc = 0;
	char tmp[MAX_LENGTH];
	char **argv = (char **)calloc(MAX_ARGS_SIZE + 1, sizeof(char *));

	Morsetree *tree;

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
	add_symbol_to_tree(tree, "----", '0');
	add_symbol_to_tree(tree, "*----", '1');
	add_symbol_to_tree(tree, "**---", '2');
	add_symbol_to_tree(tree, "***--", '3');
	add_symbol_to_tree(tree, "****-", '4');
	add_symbol_to_tree(tree, "*****", '5');
	add_symbol_to_tree(tree, "-****", '6');
	add_symbol_to_tree(tree, "-***", '7');
	add_symbol_to_tree(tree, "---**", '8');
	add_symbol_to_tree(tree, "----*", '9');

	print_menu();

	do
	{
		printf("\n--> ");
		gets(tmp);

		choise = check_command(tmp, &argc, argv);

		switch (choise)
		{
		case 0:
			load_cmf_and_print_text(argc, argv, tree);
			break;
		case 1:
			load_cmf_and_save_text(argc, argv, tree);
			break;
		case 2:
			load_text_and_print_cmf(argc, argv);
			break;
		case 3:
			load_text_and_save_cmf(argc, argv);
			break;
		case 4:
			// TODO: input with spaces
			translate_text_and_print(argv[1]);
			free_memory(argc, argv);
			break;
		case 5:
			// TODO: input with spaces
			print_cmf(argv[1]);
			free_memory(argc, argv);
			break;
		case 6:
			print_format_name(argv[1]);
			break;
		case 7:
			quit(argc, argv);
			break;
		default:
			printf("...error\n");
			break;
		}
	} 
	while (choise != NUM_OF_COMM);
}