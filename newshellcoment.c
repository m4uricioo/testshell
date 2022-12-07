#include "main.h"

int main(char **argv)
{
    char *buffer, *buffer_copy;  /* aqui se almacena el imput del usuario */
    size_t bufsize = 32; /* tamano del buffer */
    size_t characters; /* numero de caracters almacenados */
    char *token; /* almacena un puntero al primer token */ 
    int n = 0, i = 0; /*numero de tokens  */

    while(1)
    {
        printf("$ ");    /* impresion por pantalla */
        characters = getline(&buffer,&bufsize,stdin); /*determina los caracteres y almacena en buffer */

        buffer_copy = malloc(sizeof(char) * characters);  /* se reserva espacio de memoria para el buffer  */
        if (buffer_copy == NULL)
        {
            printf("malloc error\n");   /* si el buffer es nulo devuelve error  */
            return(-1);
        }

        if(fork() != 0)
                wait(NULL);

        strcpy (buffer, buffer_copy);

        token = strtok(buffer, " \n");   /* asignamos el delimitador */ 

        while (token)       /* mientras tokenize */ 
        {
            token = strtok(NULL, " \n");  /* se termina la tokenizacion con el nullo */
            n++;
        }
        n++;

        token = strtok(buffer_copy, " \n"); 
        argv = malloc (sizeof(char *) * n);   /* tokeniza y guarda en un array de punteros */
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
            printf("%s\n", token);   /* se imprime la palabra tokenizada */
        }
        argv[i] = NULL;

        int val = execve(argv[0], argv, NULL);
        if (val == -1)
                printf("error\n");
    }
    return(characters);

