#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

double heron(triangle tr) {
    double p = (tr.a + tr.b + tr.c);
    return p * (p - 2 * tr.a) * (p - 2 * tr.b) * (p - 2 * tr.c);
}

void sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (heron(*(tr + i)) > heron(*(tr + j))) {
                triangle temp = *(tr + i);
                *(tr + i) = *(tr + j);
                *(tr + j) = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));

    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);

    sort_by_area(tr, n);

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);

    return 0;
}
