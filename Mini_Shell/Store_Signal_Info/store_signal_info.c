#include "Include/main.h"


SignalNode* head = NULL;  // Head of the linked list


// Function to add the signal to the linked list
void add_signal_to_list(char *input_string,int pid) 
{

    //printf("Signal added to list\n");
    SignalNode* new_node = (SignalNode*)malloc(sizeof(SignalNode));

    if (!new_node) 
    {
        perror("Failed to allocate memory for signal node");
        return;
    }
    
    strcpy(new_node->input_string,input_string);
    new_node->pid = pid;

    new_node->next = head;
    head = new_node;
    
}

// Function to display the signals stored in the linked list
void display_signals() 
{
    SignalNode* current = head;
    printf(BYEL"\nStored Signals:\n"reset);
    printf("\n-------------------------------------------\n");
    printf(BHRED"\tSignal Name \t\t Pid\n"reset);
    printf("\n-------------------------------------------\n\n");

    while (current) 
    {
        printf("\t%-20s\t%-20d\n", current->input_string,current->pid);
        current = current->next;
    }

    printf("\n-------------------------------------------\n");

}


