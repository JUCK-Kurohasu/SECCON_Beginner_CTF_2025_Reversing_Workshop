#include <stdio.h>
#include <string.h>

unsigned char XOR(unsigned char input){
    return input ^ 0xAA;
}

unsigned char SHIFT4(unsigned char c){
    return (c << 4) | (c >> 4);
}

int main(){
    char flag[] = "ctf4b{XOR_stream_bitshift}";
    
    printf("Encrypted-flag:0x");
    for(int idx=0; idx<strlen(flag); idx++){
        printf("%02x", SHIFT4(XOR(flag[idx])));
    }
    printf("\n");
    
    return 0;
}