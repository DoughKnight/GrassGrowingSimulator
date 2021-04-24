#ifndef MENU
#define MENU

typedef struct Menu {
    char* name;
    char* options[4];
    struct Menu* next;
    int length;
} Menu;

int menu_show(Menu* menu, int start);

#endif
