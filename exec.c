#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};  /* partes del archivo que quiero ejecutar, separado por coma, null para terminar */
	
	int val = execve(argv[0], argv,NULL);
	if(val == -1)
		perror("error");
	printf("done with execve\n");

	return 0;
}
