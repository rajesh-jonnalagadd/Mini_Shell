
#include "Include/main.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<time.h>

pid_t pid1;

int status;
void scan_input(char *prompt, char *input_string)
{   
    // Variable declaration
    char *command = "\0";
    int command_type;

    while (1)
     {  
        printf(BGRN "%s:~", prompt);
        printf("" reset);

        // Clear the memory
        memset(input_string, '\0', 25);

        // Clear the output buffer
        fflush(stdout);

        // Read user input
        scanf("%[^\n]", input_string);
        __fpurge(stdin);
        
        // Customize the prompt (e.g., PS1=msh)
        if (!strncmp("PS1=", input_string, 4))
        {
            if (input_string[4] != ' ')
            {
                strcpy(prompt, &input_string[4]);
                memset(input_string, '\0', 25);
                continue;
            }
            printf("Command not found\n");
            continue;
        }


        // Check for pipes in the input
        if (strchr(input_string, '|') != NULL)
        {
            // Handle piped commands
            execute_piped_commands(input_string);
            continue;
        }


        signal(SIGTSTP, signal_handler);
        signal(SIGINT, signal_handler);
        

        // Get a command
        command = get_command(input_string);
        command_type = check_command_type(command);

        // External commands
        if (command_type == EXTERNAL)
        {
           
            pid1 = fork();
           
            if (pid1 > 0)
            {
                // Parent process
                waitpid(pid1 , &status, WUNTRACED);
                if (!WIFEXITED(status))
                {
                    printf("\nChild terminated abnormally\n");
                }
            }
            else if (pid1 == 0)
            {
                // Child process
                char *argv[10]; 
                int i = 0;


                // Tokenize input string into arguments
                char *token = strtok(input_string, " ");
             
                while (token != NULL)
                    {
                        argv[i++] = token;
                        token = strtok(NULL, " ");
                    }
                    argv[i] = NULL; // Null-terminate the argv array

                // Execute the command
                if (execvp(argv[0], argv) < 0)
                {
                    perror(argv[0]);
                    exit(1);
                }
            }
            else
            {
                perror("Fork: Failed");
                exit(1);
            }
        }
        else if (command_type == BUILDIN)
        {
            execute_internal_command(input_string);
        }
        else if (command_type != NO_COMMAND && command_type != BUILDIN && command_type != EXTERNAL)
        {
            printf("Command Not Found\n");
        }

        // Implement call to the family of echo functions
        echo(input_string, status);

     if (strcmp("jobs",input_string) == 0) 
        {
            display_signals();
        }
        input_string[0] = 0;
    }   
}
 