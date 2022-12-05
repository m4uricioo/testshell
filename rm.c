#include <unistd.h>
 #include <stdio.h>
 #include <string.h>

 int main(int argc, char *argv[]) 
 {

    char *params[4]  = {"/bin/rm", "-rf", argv[1]};

    int res = execv( "/bin/rm" , params);    

    return 0;
 }
