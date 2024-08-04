
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    /*
    fork();
    fork();
    fork(); printf("Forked \n");*/
    for(int i=0;i<3;i++){
        fork();
    }
    printf("Forked \n");
    return(0);

}