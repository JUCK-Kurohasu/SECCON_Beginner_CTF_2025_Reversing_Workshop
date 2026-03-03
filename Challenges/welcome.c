// welcome.c
#include <stdio.h>
#include <string.h>

int main() {
    char flag[] = "ctf4b{w3lc0me_to_reversing_challenge!}";
    char input[100];
    
    printf("Enter the flag: ");
    scanf("%99s", input);
    
    if (strcmp(input, flag) == 0) {
        printf("Correct!\n");
    } else {
        printf("Wrong!\n");
    }
    
    return 0;
}