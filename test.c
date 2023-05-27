#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void CheckPid(pid_t node , int class){

    if(node == 0){
        printf("failed creating this node %d \n\n", class);
    }

    else if( node == 0){
        printf("created the child %d \n",class);
    }
}

int main() {
    
    printf("this is the parent \n\n");

    pid_t pid1 = fork();
    
    CheckPid(pid1,1);

    if( pid1 == 0 ){
        pid_t pid3 = fork();
        CheckPid(pid3,3);

        pid_t pid4 = fork();
        CheckPid(pid4,4);
    }

    else {
        pid_t pid2 = fork();
        CheckPid(pid2,2);
    }   
    return 0;
}
