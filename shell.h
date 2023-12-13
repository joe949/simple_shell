#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

extern char **environ;

#define MAX_INPUT_LENGTH 100

void displayPrompt(void);
void exe_env(void);
void exe_command(char *input);

#endif
