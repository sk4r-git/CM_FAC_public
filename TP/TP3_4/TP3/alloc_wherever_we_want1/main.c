#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


void setup(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    int f = open("flag.txt", O_RDWR);
    void * flag = malloc(0x80);
    read(f, flag, 0x80);
    printf("A flag is stored at 0x%llx\nTry to read it\n");
}

void menu(){
    printf("1 -> free\n");
    printf("2 -> alloc\n");
    printf("3 -> edit\n");
    printf("4 -> read\n");
}


int get_integer_from_user(){
    char s[4];
    scanf("%2s", s);
    int a = atoi(s);
    return a;
}

int main(int argc, char ** argv){
    void * tab_alloc[16];
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
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[15]\n");
                    break;
                }
                printf("Data: \n");
                read(0, tab_alloc[idx], 8);
                break;
            case 4:
                printf("index ?\n");
                idx = get_integer_from_user();
                if(idx <0 || idx > 15){
                    printf("bad index, chunks are in tab[0] or tab[15]\n");
                    break;
                }
                printf("Data: \n");
                write(1, tab_alloc[idx], 0x100);
                break;
            default:
                continue;
        }
    }
    getchar();
}
