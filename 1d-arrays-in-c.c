#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = 0;

    for (int i = 0; i < n; i++)
        result += arr[i];

    printf("%d", result);
    free(arr);
    return 0;
}
