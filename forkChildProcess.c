#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid<0){ //fork failed
        fprintf(stderr,"Fork failed!");
        return 1;
    }
    else if (pid==0){  //child process
        execlp("/bin/bash/ls", "ls", NULL);
    }
    else {  
        wait(NULL);
        printf("Child cmplete");
    }
    return 0;
}