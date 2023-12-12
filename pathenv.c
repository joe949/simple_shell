#include "shell.h"
/**
 * printEnv - function to print environment
 * @env: array of environment
 *
 * Return: Nothing
 */
void printEnv(char *env[])
{
	int i;

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);
}
/**
 * findExe - function that handles path
 * @command: input by user
 *
 * Return: Executable or error message if it fails
 */
char *findExe(char *command)
{
	char *path = getenv("PATH");
	char *pathc = strdup(path);
	char *token = strtok(pathc, ";");
	char exeP[MAX_PATH_LENGTH];

	while (token != NULL)
	{
		snprintf(exeP, sizeof(exeP), "%s/%s", token, command);
		if (access(exeP, X_OK) == 0)
		{
			free(pathc);
			return (strdup(exeP));
		}
		token = strtok(NULL, ";");
	}
	free(pathc);
	return (NULL);
}
