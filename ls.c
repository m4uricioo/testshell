#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls",  NULL}; 
	
	int val = execve(argv[0], argv,NULL);
	if(val == -1)
		perror("error");
	printf("done with execve\n");

	return 0;
}
