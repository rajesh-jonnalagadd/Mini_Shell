#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <colour.h>


/*Macro values for returning the which type of command*/
#define BUILDIN    1
#define EXTERNAL   2
#define NO_COMMAND 3


#define MAX_COMMANDS 10
#define MAX_INPUT 1024


/*Linked list to store the signal info*/
typedef struct SignalNode 
{
    char input_string[100];
    int pid;
    struct SignalNode* next;
} SignalNode;


//function declartion
void scan_input(char *prompt, char *input_string);
char *get_command(char *input_string);
int check_command_type(char *command);
void echo(char *input_string, int status);
void execute_internal_command(char *input_string);
void signal_handler(int );

void execute_piped_commands(char *input_string);
void add_signal_to_list(char *input_string,int pid);
void display_signals();
#endif
