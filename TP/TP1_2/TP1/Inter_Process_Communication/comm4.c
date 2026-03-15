#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    srand(time(NULL));
    char var[4];
    char input[4];
    printf("You must pass 0x1000 checks this time,\nAnd always keep a shell at the end\n");
    printf("Maybe you should automate this ?\n");
    for (int i = 0; i <0x1000; i++){
        var[0] = rand() % 0xFF;
        var[1] = rand() % 0xFF;
        var[2] = rand() % 0xFF;
        var[3] = rand() % 0xFF;
        printf("My var is %s, please give me the same\n", &var);
        read(0, &input, 4);
        if(strncmp(var, input, 4) == 0){
            printf("gg, 0x%x checks until the shell\n", 0xfff - i);
        }
        else{
            printf("echec !\n");
            printf("target is : 0x%x\n", *(int *)var);
            printf("your input is : 0x%x\n", *(int *)input);
        }
    }
    system("/bin/sh");
}