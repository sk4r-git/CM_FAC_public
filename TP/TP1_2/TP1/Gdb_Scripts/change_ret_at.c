#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void win(){
    printf("gg\n");
    exit(0);
}

void waiting(){
    printf("what can you do here\n");
}

int main(int argc, char ** argv){
    waiting();
}