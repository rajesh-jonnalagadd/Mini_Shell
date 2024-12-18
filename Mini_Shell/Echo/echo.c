#include "Include/main.h"

void echo(char *input_string, int status)
{
    //echo$?
    if(strncmp("echo $?",input_string,7) == 0)
    {
        printf("%d\n",status);
    }
    
    //echo $$ --> PID of the minishell project
    if(strncmp("echo $$",input_string,7) == 0)
    {
        printf("%d\n",getpid());    
    }
    
    //echo $SHELL
    if(strncmp("echo $SHELL",input_string,11) == 0)
    {
    
        const char *env_var_name = "SHELL";
        // Get the value of the environment variable
        char *value = getenv(env_var_name);
        printf("%s\n",value);

    }
}

