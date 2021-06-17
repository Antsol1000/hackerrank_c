#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++) {
        post_office p = t.offices[i];
        printf("\t%d:\n", i);

        for (int j = 0; j < p.packages_count; j++)
            printf("\t\t%s\n", p.packages[j].id);
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office* source_office = &source->offices[source_office_index];
    post_office* target_office = &target->offices[target_office_index];
    package* rejected = (package *)malloc(0);
    int rejected_count = 0;

    for (int i = 0; i < source_office->packages_count; i++) {
        package p = source_office->packages[i];
        int w = p.weight;

        if (target_office->min_weight <= w && w <= target_office->max_weight) {
            target_office->packages = (package *) realloc(
                                          target_office->packages,
                                          sizeof(package) * (++target_office->packages_count)
                                      );
            target_office->packages[target_office->packages_count - 1] = p;
        }
        else {
            rejected = (package *) realloc(
                           rejected,
                           sizeof(package) * (++rejected_count)
                       );
            rejected[rejected_count - 1] = p;
        }
    }

    source_office->packages = rejected;
    source_office->packages_count = rejected_count;
}

town town_with_most_packages(town* towns, int towns_count) {
    int most_packages = 0;
    town result = towns[0];

    for (int i = 0; i < towns_count; i++) {
        town t = towns[i];
        int t_packages = 0;

        for (int j = 0; j < t.offices_count; j++)
            t_packages += t.offices[j].packages_count;

        if (t_packages > most_packages) {
            most_packages = t_packages;
            result = t;
        }
    }

    return result;
}

town* find_town(town* towns, int towns_count, char* name) {
    int size = 0;
    town* result = (town *) malloc(size);

    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            result = (town *) realloc(result, ++size);
            result[size - 1] = towns[i];
        }
    }

    return result;
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town) * towns_count);

    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);

        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);

            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];

    while (queries--) {
        int type;
        scanf("%d", &type);

        switch (type) {
            case 1:
                scanf("%s", town_name);
                town* t = find_town(towns, towns_count, town_name);
                print_all_packages(*t);
                break;

            case 2:
                scanf("%s", town_name);
                town* source = find_town(towns, towns_count, town_name);
                int source_index;
                scanf("%d", &source_index);
                scanf("%s", town_name);
                town* target = find_town(towns, towns_count, town_name);
                int target_index;
                scanf("%d", &target_index);
                send_all_acceptable_packages(source, source_index, target, target_index);
                break;

            case 3:
                printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
                break;
        }
    }

    return 0;
}
