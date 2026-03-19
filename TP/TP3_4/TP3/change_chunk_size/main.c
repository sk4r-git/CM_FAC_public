#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void setup(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
}

void menu(){
    printf("1 -> free\n");
    printf("2 -> alloc\n");
    printf("3 -> edit\n");
    printf("4 -> create misterious chunk\n");
    printf("5 -> free misterious chunk\n");
    printf("6 -> exec misterious chunk\n");
}


int get_integer_from_user(){
    char s[4];
    scanf("%2s", s);
    int a = atoi(s);
    return a;
}

int main(int argc, char ** argv){
    void * tab_alloc[16];
    char * misterious_cunk;
    char binsh[8] = "/bin/ls\x00";
    int choice;
    int idx;
    setup();
    while(1){
        menu();
        choice = get_integer_from_user();
        if(choice <=0 || choice > 6){
            printf("choice beween one and 4 pls\n");
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
                free(tab_alloc[idx]);
                break;
            case 2:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[15]\n");
                    break;
                }
                tab_alloc[idx] = malloc(16);
                break;
            case 3:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 1){
                    printf("bad index, chunks are in tab[0] or tab[1]\n");
                    break;
                }
                printf("Data: \n");
                read(0, tab_alloc[idx], 25);
                break;
            case 4:
                misterious_cunk = malloc(0x20);
                strcpy(misterious_cunk, binsh);
                printf("misterious chunk allocated\n");
                break;
            case 5:
                free(misterious_cunk);
                printf("misterious chunk freed\n");
                break;
            case 6:
                system(misterious_cunk);
                break;
            default:
                continue;
        }
    }
    getchar();
}