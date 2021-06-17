#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s) {
    // find the largest k such that s[k] < s[k + 1]
    int k = -1;

    for (int i = 0; i < n - 1; i++) {
        if (strcmp(s[i], s[i + 1]) < 0)
            k = i;
    }

    if (k == -1)
        return 0;

    // find the largest l such that s[k] < s[l]
    int l = -1;

    for (int i = k + 1; i < n; i++)
        if (strcmp(s[k], s[i]) < 0)
            l = i;

    // swap s[k] with s[l]
    char *temp = s[k];
    s[k] = s[l];
    s[l] = temp;

    // reverse array from s[k + 1] to s[n]
    for (int i = k + 1, j = n - 1; i < j; i++, j--) {
        char *temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    return 1;
}

int main()
{
    char **s;
    int n;
    scanf("%d", &n);
    s = calloc(n, sizeof(char*));

    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }

    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    }
    while (next_permutation(n, s));

    for (int i = 0; i < n; i++)
        free(s[i]);

    free(s);
    return 0;
}
