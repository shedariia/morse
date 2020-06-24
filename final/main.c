#include "morse.h"

void main(void)
{
	int choise = 0;
	int argc = 0;
	char tmp[MAX_LENGTH];
	char **argv = (char **)malloc((MAX_ARGS_SIZE + 1) * sizeof(char *));

	print_menu();

	do
	{
		printf("--> ");
		gets(tmp);

		choise = check_command(tmp, &argc, argv);

		switch (choise)
		{
		case 0:
			load_cmf_and_print_text(argc, argv);
			break;
		case 1:
			load_cmf_and_save_text(argc, argv);
			break;
		case 2:
			load_text_and_print_cmf(argc, argv);
			break;
		case 3:
			load_text_and_save_cmf(argc, argv);
			break;
		case 4:
			translate_text_and_print(argv[1]);
			break;
		case 5:
			translate_cmf_and_print(argv[1]);
			break;
		case 6:
			print_format_name(argv[1]);
			break;
		case 7:
			quit(argv);
			break;
		default:
			printf("...error\n");
			break;
		}
	} 
	while (choise != NUM_OF_COMM);
}