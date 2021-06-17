#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int max_and = 0, max_or = 0, max_xor = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;

            int and = i & j;
            int or = i | j;
            int xor = i ^ j;
            max_and = ( and > max_and && and < k) ? and : max_and;
            max_or = ( or > max_or && or < k) ? or : max_or;
            max_xor = (xor > max_xor && xor < k) ? xor : max_xor;
        }
    }

    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}
