/* LIBRARIES */
#include "morse.h"	/* check_command(), print_format_name(), ... */

/* MAIN function */
void main(void)
{
	Morsetree * tree = NULL;
	int choise = 0;
	int argc = 0;
	char tmp[MAX_LENGTH];
	char **argv = (char **)calloc(MAX_ARGS_SIZE + 1, sizeof(String));

	tree = fill_tree(tree);
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
			load_text_and_translate_cmf_and_print(argc, argv);
			break;
		case 3:
			load_text_and_save_cmf(argc, argv);
			break;
		case 4:
			translate_text_and_print(argv[1]);
			break;
		case 5:
			translate_cmf_and_print(argv[1], tree);
			break;
		case 6:
			print_format_name(argv[1]);
			break;
		case 7:
			quit(argc, argv);
			break;
		default:
			printf("... error.\n");
			break;
		}
	} 
	while (choise != NUM_OF_COMM);
}