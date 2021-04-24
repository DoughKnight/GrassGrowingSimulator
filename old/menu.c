#include <stdio.h>
#include "menu.h"

int menu_show(Menu* menu, int start) {
    int input = -3;
    while(input == -3) {
        printf("---- %s ----\n", menu->name);
        if(start > 1) {
            printf("-2) Back\n");
        }
        else {
            printf("-2) Exit\n");
        }
        for(int i = 0; i < menu->length; i++) {
           printf(" %d) %s\n", i+start, menu->options[i]);
        }
        if(menu->next != NULL) {
            printf("-1) %s\n", menu->next->name);
        }
        scanf("%d", &input);
        if(input == -1) {
            input = menu_show(menu->next, menu->length+start);
        }
        else if(input == -2) {
            return -3;
        }
    }
    return input;
}
