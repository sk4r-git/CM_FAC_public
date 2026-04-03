#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv){
    srand(time(NULL));
    int a = rand();
    int ur_input = 0;
    if(a == ur_input){
        printf("gg\n");
    }
    else{
        printf("try again\n");
    }
}

