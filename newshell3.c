#include "main.h"

int main(char **argv)
{
    char *buffer, *buffer_copy;
    size_t bufsize = 32;
    size_t characters;
    char *token;
    int n = 0, i = 0;

    while(1)
    {
        printf("$ ");
        characters = getline(&buffer,&bufsize,stdin);

        buffer_copy = malloc(sizeof(char) * characters);
        if (buffer_copy == NULL)
        {
            printf("malloc error\n");
            return(-1);
        }

        if(fork() != 0)
                wait(NULL);

        strcpy (buffer, buffer_copy);

        token = strtok(buffer, " \n");

        while (token)
        {
            token = strtok(NULL, " \n");
            n++;
        }
        n++;

        token = strtok(buffer_copy, " \n");
        argv = malloc (sizeof(char *) * n);
        while(token)
        {
            argv[i] = malloc (sizeof(char) * strlen(token));
            if (argv[i] == NULL)
            {
                    printf("malloc error\n");
                    return (-1);
            }
            strcpy(argv[i], token);
            token = strtok(NULL, " \n");
            i++;
            printf("%s\n", token);
        }
        argv[i] = NULL;

        int val = execve(argv[0], argv, NULL);
        if (val == -1)
                printf("error\n");
    }
    return(characters);
}
