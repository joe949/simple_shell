#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

extern char **environ;

#define MAX_INPUT_LENGTH 100
#define MAX_ARG_COUNT 10
#define MAX_PATH_LENGTH 1024

void displayPrompt(void);
void executeCommand(const char *command, char *args[]);
void checkInput(char *input, char *command, char *args[], int *argc);
void freeArgs(char *args[], int argc);
void printEnv(char *env[]);
char *findExe(char *command);

#endif
