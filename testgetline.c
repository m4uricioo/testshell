#include <stdio.h>

int input(char *s,int length);

int main()
{
    char buffer[32];
    char *b = buffer;
    size_t bufsize = 32;
    

    printf("Type something: ");
    characters = getline(&b,&bufsize,stdin);
    
    printf(": '%s'\n",buffer);

    return(0);
}
