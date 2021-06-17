#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1000 * sizeof(char));
    scanf("%s", s);
    int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 1000; i++) {
        if ('0' <= s[i] && s[i] <= '9')
            counter[(int)(s[i] - '0')]++;
    }

    for (int i = 0; i < 10; i++)
        printf("%d ", counter[i]);

    free(s);
    return 0;
}
