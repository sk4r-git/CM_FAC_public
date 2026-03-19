#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void setup(void ** tab){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    printf("2 chunks are already alocated on heap for you\n");
    printf("if you manage to bypass protection and free one 5 times,\n");
    printf("You will get a shell\n");
    printf("chunks are at 0x%llx, and 0x%llx\n", tab[0], tab[1]);
}

void menu(){
    printf("you can choose to free one, or edit one\n");
    printf("1 -> free\n");
    printf("2 -> edit\n");
}

void win(){
    system("/bin/sh");
}

int get_integer_from_user(){
    char s[4];
    scanf("%2s", s);
    int a = atoi(s);
    return a;
}

int main(int argc, char ** argv){
    void * tab_alloc[2];
    int choice;
    int idx;
    int freed[2] = {0};
    char payload[16];
    *tab_alloc = malloc(16);
    *(tab_alloc + 1) = malloc(16);
    setup(tab_alloc);
    while(1){
        menu();
        choice = get_integer_from_user();
        if(choice <=0 || choice > 2){
            printf("choice beween one and 4 pls\n");
            continue;
        }
        switch(choice){
            case 1:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 1){
                    printf("bad index, chunks are in tab[0] or tab[1]\n");
                    break;
                }
                free(tab_alloc[idx]);
                freed[idx]++;
                break;
            case 2:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 1){
                    printf("bad index, chunks are in tab[0] or tab[1]\n");
                    break;
                }
                printf("Data: \n");
                scanf("%16s", tab_alloc[idx]);
                break;
            default:
                continue;
        }
        if(freed[0] == 5 || freed[1] == 5){
            win();
        }
    }
    getchar();
}