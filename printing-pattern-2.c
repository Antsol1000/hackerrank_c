#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (j < i)
                printf("%d ", i);
            else
                printf("%d ", j);
        }

        for (int j = 2; j <= n; j++) {
            if (j < i)
                printf("%d ", i);
            else
                printf("%d ", j);
        }

        printf("\n");
    }

    for (int i = 2; i <= n; i++) {
        for (int j = n; j > 0; j--) {
            if (j < i)
                printf("%d ", i);
            else
                printf("%d ", j);
        }

        for (int j = 2; j <= n; j++) {
            if (j < i)
                printf("%d ", i);
            else
                printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}
