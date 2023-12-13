#include "shell.h"
/**
 * exe_command - function that executes command
 * @input: command entered by user
 *
 * Return: Nothing
 */
void exe_command(char *input)
{
	pid_t pid = fork();
	char *tk, *args[64];
	int status, argc = 0;

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		tk = strtok(input, " ");

		while (tk != NULL)
		{
			args[argc++] = tk;
			tk = strtok(NULL, " ");
		}
		args[argc] = NULL;

		if (argc == 0)
			exit(EXIT_SUCCESS);

		execvp(args[0], args);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
			printf("Exit status %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("Exit status %d\n", WTERMSIG(status));
	}
}

/**
 * exe_env - function to handle environment
 *
 * Return: Nothing
 */
void exe_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
