#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char var[4] = "\xef\xbe\xad\xde";
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