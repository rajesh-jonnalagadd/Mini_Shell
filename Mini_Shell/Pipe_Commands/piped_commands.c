#include"Include/main.h"

void execute_piped_commands(char *input) 
{    
    
    char *commands[MAX_COMMANDS];
    int num_commands = 0;

    // Split the input string into commands based on "|"
    char *token = strtok(input, "|");
    while (token != NULL) 
    {
        commands[num_commands++] = token;
        token = strtok(NULL, "|");
    }

    int pipefds[2 * (num_commands - 1)];
    for (int i = 0; i < num_commands - 1; i++)
    {
        if (pipe(pipefds + i * 2) < 0) {
            perror("Pipe creation failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_commands; i++) 
    {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            if (i != 0) 
            {
                // Not the first command: connect input to previous pipe
                if (dup2(pipefds[(i - 1) * 2], STDIN_FILENO) < 0) 
                {
                    perror("dup2 input failed");
                    exit(EXIT_FAILURE);
                }
            }
            if (i != num_commands - 1) 
            {
                // Not the last command: connect output to next pipe
                if (dup2(pipefds[i * 2 + 1], STDOUT_FILENO) < 0) 
                {
                    perror("dup2 output failed");
                    exit(EXIT_FAILURE);
                }
            }

            // Close all pipe fds in the child
            for (int j = 0; j < 2 * (num_commands - 1); j++) 
            {
                close(pipefds[j]);
            }

            // Execute the command
            char *cmd_args[MAX_INPUT];
            int arg_count = 0;

            // Tokenize the command into arguments
            char *arg = strtok(commands[i], " ");
            while (arg != NULL) 
            {
                cmd_args[arg_count++] = arg;
                arg = strtok(NULL, " ");
            }
            cmd_args[arg_count] = NULL;

            execvp(cmd_args[0], cmd_args);
            perror("Execution failed");
            exit(EXIT_FAILURE);
            
        } else if (pid < 0) 
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipe fds in the parent
    for (int i = 0; i < 2 * (num_commands - 1); i++)
    {
        close(pipefds[i]);
    }

    // Wait for all child processes
    for (int i = 0; i < num_commands; i++) {
        wait(NULL);
    }
}
