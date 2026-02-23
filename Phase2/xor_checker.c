#include <stdio.h>
#include <string.h>
#include <stdint.h>

const uint8_t XOR_KEY = 0x42;
const uint8_t encrypted_flag[] = {
    0x21, 0x16, 0x20, 0x00, 0x22, 0x69, 0x3a, 0x2d, 0x14, 0x63, 
    0x4d, 0x13, 0x63, 0x2e, 0x2d, 0x16, 0x63, 0x11, 0x45, 0x21, 
    0x17, 0x14, 0x45, 0x7b
};

void print_banner() {
    printf("=================================\n");
    printf("  Welcome to XOR Flag Checker!  \n");
    printf("=================================\n");
    printf("Hint: The key is 0x42\n");
    printf("\n");
}

int check_flag(const char *input) {
    int len = strlen(input);
    
    if (len != sizeof(encrypted_flag)) {
        return 0;
    }
    
    // XOR each byte and compare
    for (int i = 0; i < len; i++) {
        if ((uint8_t)input[i] != (encrypted_flag[i] ^ XOR_KEY)) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char input[256];
    
    print_banner();
    printf("Enter the flag: ");
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    
    // Remove newline
    input[strcspn(input, "\n")] = 0;
    
    if (check_flag(input)) {
        printf("\n✓ Correct! That's the flag!\n");
    } else {
        printf("\n✗ Wrong flag. Try again!\n");
    }
    
    return 0;
}