/* LIBRARIES */
#include "morse.h"	/* check_command(), print_format_name(), ... */

/* MAIN function */
void main(void)
{
	int choise = 0;
	int argc = 0;
	char tmp[MAX_LENGTH];
	char **argv = (char **)malloc((MAX_ARGS_SIZE + 1) * sizeof(char *));

	Morsetree *r;

	r = morsetree('|');
	add_morse(r, ".-", 'A');
	add_morse(r, "-...", 'B');
	add_morse(r, "-.-.", 'C');
	add_morse(r, "-..", 'D');
	add_morse(r, ".", 'E');
	add_morse(r, "..-.", 'F');
	add_morse(r, "--.", 'G');
	add_morse(r, "....", 'H');
	add_morse(r, "..", 'I');
	add_morse(r, ".---", 'J');
	add_morse(r, "-.-", 'K');
	add_morse(r, ".-..", 'L');
	add_morse(r, "--", 'M');
	add_morse(r, "-.", 'N');
	add_morse(r, "---", 'O');
	add_morse(r, ".--.", 'P');
	add_morse(r, "--.-", 'Q');
	add_morse(r, ".-.", 'R');
	add_morse(r, "...", 'S');
	add_morse(r, "-", 'T');
	add_morse(r, "..-", 'U');
	add_morse(r, "...-", 'V');
	add_morse(r, ".--", 'W');
	add_morse(r, "-..-", 'X');
	add_morse(r, "-.--", 'Y');
	add_morse(r, "--..", 'Z');
	add_morse(r, "----", '0');
	add_morse(r, ".----", '1');
	add_morse(r, "..---", '2');
	add_morse(r, "...--", '3');
	add_morse(r, "....-", '4');
	add_morse(r, ".....", '5');
	add_morse(r, "-....", '6');
	add_morse(r, "-...", '7');
	add_morse(r, "---..", '8');
	add_morse(r, "----.", '9');

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