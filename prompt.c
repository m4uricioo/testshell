
/* The first function prints the first request string, or PS1 ,
 * which you generally see when the shell is waiting 
 * for you to enter a command. The second function prints the second request string, or PS2 ,
 *  which the shell prints when it enters a multi-line command. */


#include <stdio.h>
#include "shell.h"

void print_prompt1(void)
{
    fprintf(stderr, "$ ");
}

void print_prompt2(void)
{
    fprintf(stderr, "> ");
}
