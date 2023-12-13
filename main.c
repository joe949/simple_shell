#include "shell.h"

/**
 * displayPrompt - function that displays a prompt
 *
 * Return: Nothing
 */
void displayPrompt(void)
{
	printf("shell$ ");
}

/**
 * main - main function
 *
 * Return: 0 on success
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	size_t len;

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

		if (strcmp(input, "exit") == 0)
			break;
		else if (strcmp(input, "env") == 0)
		{
			exe_env();
		}
		else
		{
			exe_command(input);
		}
	}
	return (0);
}
