#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

	int main(int argc, char **argv)
	{
		char *cmd;
                                 /* Our main()function calls two custom functions, print_prompt1() and read_cmd(). 
				  * The first function prints the request string and the second reads the next line
				  * of input. Let's take a closer look at these two functions. */
		do
		
		{
		 
		print_prompt1();

		cmd = read_cmd();

		if(!cmd)

		{

		exit(EXIT_SUCCESS);

		}


		
	if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
	
	{

		free(cmd);
		continue;

	}

	if(strcmp(cmd, "exit\n") == 0)

	{

		free(cmd);

		break;

	}

	printf("%s\n", cmd);

	free(cmd);

		} while(1);

		exit(EXIT_SUCCESS);

	}
char *read_cmd(void)
{
    char buf[1024];
    char *ptr = NULL;
    char ptrlen = 0;

    while(fgets(buf, 1024, stdin))
    {
        int buflen = strlen(buf);

        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
        else
        {
            char *ptr2 = realloc(ptr, ptrlen+buflen+1);

            if(ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }

        if(!ptr)
        {
            fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
            return NULL;
        }

        strcpy(ptr+ptrlen, buf);

        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            print_prompt2();
        }

        ptrlen += buflen;
    }

    return ptr;
}


/* Here we read the input from stdin in 1024-byte chunks and store the input in a buffer.
 *  The first time we read the input (the first fragment of the current command), we create our buffer
 *   usingandomalloc(). For subsequent fragments, we expand the buffer usandorealloc(). We should not encounter any memory
 *    problems here, but if something incorrect happens, we print an error message and returnNULL.
 *     If all goes well, we copy the input fragment we just read from the user to our buffer and adjust our pointers accordingly. */
