#include <stdio.h>
#include <string.h>

struct Menu {
    char* name;
    char* options[4];
    struct Menu* next;
    int length;
};

int menu_show(struct Menu* menu, int start) {
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

int main(int argc, char* argv[]) {


    struct Menu menu2;
    menu2.name = "About";
    menu2.options[0] = "Instructions";
    menu2.options[1] = "Lore";
    menu2.next = NULL;
    menu2.length = 2;

    struct Menu menu;
    menu.name = "Main Menu";
    menu.options[0] = "Story (Tutorial)";
    menu.options[1] = "Grand Campaign";
    menu.options[2] = "Versus";
    menu.options[3] = "Settings";
    menu.length = 4;
    menu.next = &menu2;

    int ans = menu_show(&menu, 1);
    printf("%d\n", ans);
}
