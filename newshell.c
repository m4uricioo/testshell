#include "shell.h"
int main(char *argv)
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    char *token;
    int n = 0;
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        printf("malloc error\n");
        return (-1);
    }
    while(1)
    {
    printf("$ ");
    characters = getline(&buffer,&bufsize,stdin);
    token = strtok(buffer, " ");
    while (token)
    {
            printf("%s\n", token);
            token = strtok(NULL, " ");
            n++;
    }
    }
    return(characters);
}
