#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b) > 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ca[26], cb[26];

    for (int i = 0; i < 26; i++) {
        ca[i] = 0;
        cb[i] = 0;
    }

    for (int i = 0; i < strlen(a); i++)
        ca[a[i] - 'a']++;

    for (int i = 0; i < strlen(b); i++)
        cb[b[i] - 'a']++;

    int ra = 0, rb = 0;

    for (int i = 0; i < 26; i++) {
        ra += ca[i] > 0;
        rb += cb[i] > 0;
    }

    if (ra == rb)
        return lexicographic_sort(a, b);

    return ra > rb;
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b))
        return lexicographic_sort(a, b);

    return strlen(a) > strlen(b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) == 1) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    printf("\n");
    string_sort(arr, n, lexicographic_sort_reverse);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    printf("\n");
    string_sort(arr, n, sort_by_length);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    printf("\n");
    string_sort(arr, n, sort_by_number_of_distinct_characters);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    printf("\n");
}
