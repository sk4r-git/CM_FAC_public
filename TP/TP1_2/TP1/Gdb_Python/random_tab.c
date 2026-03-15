#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv){
    srand(time(NULL));
    int a;
    for(int i = 0; i< 0x100; i++){
        a = rand();
    }
}