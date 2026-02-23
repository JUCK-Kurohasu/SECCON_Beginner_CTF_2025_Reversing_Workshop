#include <stdio.h>

void print_part3() {
    printf("_ch41n}");
}

void print_part2() {
    printf("funct10n");
    print_part3();
}

void print_part1() {
    printf("ctf4b{");
    print_part2();
}

int main() {
    printf("Flag parts are scattered across functions!\n");
    print_part1();
    printf("\n");
    return 0;
}