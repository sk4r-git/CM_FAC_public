#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    char var[4];
    srand(time(NULL));
    var[0] = rand() % 0xFF;
    var[1] = rand() % 0xFF;
    var[2] = rand() % 0xFF;
    var[3] = rand() % 0xFF;
    printf("My var is %s, please give me the same\n", &var);
    char input[4];
    read(0, &input, 4);
    if(strncmp(var, input, 4) == 0){
        printf("Will you keep my shell ?\n");
        system("/bin/sh");
    }
    else{
        printf("echec !\n");
        printf("target is : 0x%x\n", *(int *)var);
        printf("your input is : 0x%x\n", *(int *)input);
    }
}