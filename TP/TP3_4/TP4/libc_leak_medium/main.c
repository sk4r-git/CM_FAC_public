#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>


void setup(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
}

void menu(){
    printf("1 -> alloc\n");
    printf("2 -> free\n");
    printf("3 -> edit\n");
    printf("4 -> read\n");
    printf("5 -> check\n");
    printf("6 -> quit\n");
}


int get_integer_from_user(){
    char s[4];
    scanf("%2s", s);
    int a = atoi(s);
    return a;
}

long get_long_from_user(){
    char s[24];
    scanf("%20s", s);
    long a = atol(s);
    return a;
}

int main(int argc, char ** argv){
    void * tab_alloc[16];
    int tab_size[16];
    long choice;
    int idx;
    int size;
    setup();
    while(1){
        menu();
        choice = get_integer_from_user();
        if(choice <=0 || choice > 6){
            printf("choice beween 1 and 6 pls\n");
            continue;
        }
        switch(choice){
            case 1:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[15]\n");
                    break;
                }
                printf("size ?\n");
                size = get_long_from_user();
                if(size <0 || size > 0x200){
                    printf("Wow, calm down\n");
                    break;
                }
                tab_alloc[idx] = malloc(size);
                tab_size[idx] = size;
                break;

            case 2:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[15]\n");
                    break;
                }
                free(tab_alloc[idx]);
                break;

            case 3:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[1]\n");
                    break;
                }
                printf("Data: \n");
                read(0, tab_alloc[idx], tab_size[idx] + 16);
                break;

            case 4:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[1]\n");
                    break;
                }
                printf("Data: \n");
                write(1, tab_alloc[idx], tab_size[idx] + 16);
                break;

            case 5:
                printf("Ok, where is the base of the libc ?\n");
                long guess = get_long_from_user();
                Dl_info info;
                dladdr((void *)printf, &info);
                if((long)info.dli_fbase == guess){
                    printf("GG\n");
                    system("/bin/sh");
                }
                else{
                    printf("Libc base address: %p\n", info.dli_fbase);
                    printf("Your guess: %p\n", guess);
                    printf("Libc path: %s\n", info.dli_fname);   
                } 
            case 6:
                exit(0);
                
            default:
                continue;
        }
    }
    getchar();
}