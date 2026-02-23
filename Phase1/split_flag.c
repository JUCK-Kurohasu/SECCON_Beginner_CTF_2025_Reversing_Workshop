#include <stdio.h>
#include <string.h>

char part1[] = "ctf4b{";
char part2[] = "spl1t_";
char part3[] = "fl4g_";
char part4[] = "p4rts}";

void show_flag() {
    char full[100];
    strcpy(full, part1);
    strcat(full, part2);
    strcat(full, part3);
    strcat(full, part4);
    printf("Flag: %s\n", full);
}

int main() {
    printf("The flag is split into multiple parts!\n");
    show_flag();
    return 0;
}