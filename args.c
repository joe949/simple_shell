#include "shell.h"
/**
 * executeCommand - function that executs command input by user
 * @command: input by user
 * @args: array of arguments
 *
 * Return: Nothing
 */
void executeCommand(const char *command, char *args[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execvp(command, args);
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			printf("Process exited with status %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("Process terminated by signal %d\n", WTERMSIG(status));
	}
}
/**
 * checkInput - function that splits input into command and args
 * @input: input from user
 * @command: command of user
 * @args: array of arguments
 * @argc: argument count
 *
 * Return: Nothing
 */
void checkInput(char *input, char *command, char *args[], int *argc)
{
	char *token = strtok(input, " ");
	*argc = 0;

	while (token != NULL && *argc < MAX_ARG_COUNT)
	{
		if (*argc == 0)
			strcpy(command, token);
		else
			args[*argc - 1] = strdup(token);

	token = strtok(NULL, " ");
	(*argc)++;
	}
	args[*argc - 1] = NULL;
}

/**
 * freeArgs - function to free memory allocated to arguments
 * @args: array of arguments
 * @argc: arguments count
 *
 * Return: Nothing
 */
void freeArgs(char *args[], int argc)
{
	int i;

	for (i = 0; i < argc; i++)
		free(args[i]);
}
