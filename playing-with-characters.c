#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char c;
    char s[100], sen[100];
    scanf("%c", &c);
    scanf("%s\n", &s);
    scanf("%[^\n]s", &sen);
    printf("%c\n", c);
    printf("%s\n", s);
    printf("%s\n", sen);
    return 0;
}
