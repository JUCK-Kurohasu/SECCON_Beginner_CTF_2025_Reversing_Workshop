#include <stdio.h>

int main() {
    printf("Hex flag: ");
    char flag[] = "ctf4b{h3x_t0_4sc11}";
    for (int i = 0; flag[i]; i++) {
        printf("%02x", flag[i]);
    }
    printf("\n");
    
    return 0;
}