#include <stdio.h>
#include <string.h>

int check_password(char *input) {
    char password[] = "sup3r_s3cr3t_p4ssw0rd";
    return strcmp(input, password) == 0;
}

int main() {
    char input[100];
    
    printf("Enter password: ");
    scanf("%99s", input);
    
    if (check_password(input)) {
        printf("Access granted!\n");
        printf("Flag: ctf4b{strcmp_ch3ck_byp4ss3d}\n");
    } else {
        printf("Access denied!\n");
    }
    
    return 0;
}