#include <stdio.h>

int main() {
    char fake1[] = "fake{this_is_not_the_flag}";
    char fake2[] = "ctf{almost_but_not_quite}";
    char real[] = "ctf4b{gr3p_p4tt3rn_m4st3r}";
    char fake3[] = "flag{nice_try}";
    
    printf("There are many strings...\n");
    printf("But only one is the real flag!\n");
    
    return 0;
}