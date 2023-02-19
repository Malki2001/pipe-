#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd[2];
    //fd[0]=read   fd[1]=write
    char received_messg[20];

    if(pipe(fd < 0)){
        printf("An error occured with opening the pipe");
        exit(1);
    }

    int pid=fork();
    if(pid < 0){
        printf("An error occured with fork");
        exit(2);
    }

    else if(pid != 0){
        close(fd[0]);
        write(fd[1],"Hello from parent",20)
        close(fd[1]);
        exit(0);
    }

    else{
       close(fd[1]);
       read(fd[0] , received_messg,20);
       printf("Got from parent =: %s",received_messg);
       close(fd[0]);
       exit(0);
    }

}