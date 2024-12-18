#include "Include/main.h"

/* Message like user_name and virtual_box_name*/
char prompt[25] = "Rajesh@Rajesh-VirtualBox";
char input_string[250];

extern int status;
extern pid_t pid1;

int main()
{
    /* To Get the input command from the user*/
    scan_input(prompt, input_string);

    return 0;
}


/* Signal Handler fot the input signal*/
void signal_handler(int num)
{
       if(num == SIGINT)
       {
            printf(BGRN"\n%s:~",prompt);
            printf(""reset);
            fflush(stdout);

       }
       else if(num == SIGTSTP)
       {
            if(*input_string)
            add_signal_to_list(input_string,pid1);
            else
            printf(BGRN"\n%s:~",prompt);
            printf(""reset);
            fflush(stdout);
        }
        

}

