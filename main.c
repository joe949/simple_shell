#include "shell.h"

/**
 * displayPrompt - function that displays a prompt
 *
 * Return: Nothing
 */
void displayPrompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * main - main function
 *
 * Return: 0 on success
 */
int main(void)
{
	char command[MAX_INPUT_LENGTH];
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_COUNT];
	int len, argc;
	char *exeP = findExe(command);

	while (1)
	{
		displayPrompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
		checkInput(input, command, args, &argc);

		if (strcmp(command, "exit") == 0)
			break;
		if (strcmp(command, "env") == 0)
		{
			printEnv(environ);
			continue;
		}
		if (exeP != NULL)
		{
			executeCommand(exeP, args);
			freeArgs(args, argc - 1);
			free(exeP);
		}
		else
		{
			printf("Command not found: %s\n", command);
			freeArgs(args, argc - 1);
		}
	}
	return (0);
}
