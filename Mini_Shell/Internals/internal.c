#include "Include/main.h"

void execute_internal_command(char *input_string)
{
    char buffer[1024];
    
    //Exit-->terminate the program
    if(strcmp("exit",input_string) == 0)
    {
        _Exit(0);
    }
    
    //PWD -> print the current location
    if(strcmp("pwd",input_string) == 0)
    {
        if (getcwd(buffer, sizeof(buffer)) != NULL) 
        {
            printf("%s\n", buffer);
        }
        else 
        {
            perror("getcwd error");
        }     

    }
    /* To clear the terminal screen*/
    if(strcmp("clear",input_string) == 0)
    {
        system("clear");
        
    }
    
    //cd-->change the directory
    //input_string -> cd abc
    if(strncmp("cd",input_string,2) == 0) 
    {
        //implement cd command with mulitiple spaces
        //varible declartion
        int i,count=0;
        for(i = 2 ; input_string[i] == ' ' ; i++)
        {
            count++;
        }
       
       char *path = &input_string[2 + count];

        // Check if path is empty
        if (strlen(path) == 0)
        {
            fprintf(stderr, "cd: Missing operand\n");
        } 
        else 
        {
            // Change directory
            if (chdir(path) == 0) {
                printf("Directory changed to: %s\n", path);
            } else {
                perror("cd error");
            }
        }
    }    


}

