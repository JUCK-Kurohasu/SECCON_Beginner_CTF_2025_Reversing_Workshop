#include <stdio.h>

int main() {
    // "ctf4b{b4s364_dec0d1ng_is_easy}" in Base64
    char encoded[] = "Y3RmNGJ7YjRzMzY0X2RlYzBkMW5nX2lzX2Vhc3l9";
    
    printf("Encoded flag: %s\n", encoded);
    printf("Hint: This looks like Base64...\n");
    
    return 0;
}