#include <stdio.h>
#include <string.h>
#include "menu.h"

const int FIELD = 0;
const int HILLOCK = 1;
const int DALE = 2;

int map[12][12] =
{
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void campaign() {
    
}

int main(int argc, char* argv[]) {

    Menu menu2;
    menu2.name = "About";
    menu2.options[0] = "Instructions";
    menu2.options[1] = "Lore";
    menu2.next = NULL;
    menu2.length = 2;

    Menu menu;
    menu.name = "Main Menu";
    menu.options[0] = "Story (Tutorial)";
    menu.options[1] = "Grand Campaign";
    menu.options[2] = "Versus";
    menu.options[3] = "Settings";
    menu.length = 4;
    menu.next = &menu2;

    int ans = menu_show(&menu, 1);
    switch (ans) {
        case 1:
            printf("Welcome to the story!\n");
            break;
        case 2:
            printf("---- Grand Campaign ----\n");
            for(int i = 0; i < 12; i++) {
                for(int j = 0; j < 12; j++) {
                    printf("%2d", map[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Versus Here.");
            break;
        case 4:
            printf("There are no graphics.");
            break;
        case 5:
            printf("");
            break;
        case 6:
            printf("");
            break;
    }
}
