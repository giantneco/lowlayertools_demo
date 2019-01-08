#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct person {
    int age;
    char *name;
} *person_t;

#define PERSON_NAME(x) ((x)->name)
#define PERSON_AGE(x) ((x)->age)

person_t
new_person(const char * name, int age)
{
    if (name == NULL) {
        return NULL;
    }
    size_t len = strlen(name);
    if (len == 0) {
        return NULL;
    }
    person_t p = (person_t) malloc (sizeof(person_t*));
    PERSON_NAME(p) = (char *) malloc (len);
    strncpy(PERSON_NAME(p), name, len);    
    PERSON_AGE(p) = age;
    return p;
}

person_t *
person_list(void)
{
    person_t * p = (person_t *) malloc (sizeof(person_t) * 6);

    p[0] = new_person("Alice", 25);
    p[1] = new_person("Bob", 30);
    p[2] = new_person("Charry", 28);
    p[3] = new_person("David", 14);
    p[4] = new_person("Eric", 55);
    p[5] = NULL;

    return p;
}

bool
find_persons_by_name(const person_t * p, const char * name)
{
    if (!p) {
        return false;
    }
    for (int i = 0; p[i] != NULL; i++) {
        if (strcmp(name, PERSON_NAME(p[i])) == 0) {
            return true;
        }
    }
    return false;
}

int
rename_person(person_t * p, const char * old, const char * new)
{
    int count = 0;
    for (int i = 0; p[i] != NULL; i++) {
        if (strcmp(old, PERSON_NAME(p[i])) == 0) {
            size_t len = strlen(new);
            PERSON_NAME(p[i]) = (char*)malloc(len); // Memory Leak !
            strncpy(PERSON_NAME(p[i]), new, len);
            count++;
        }
    }
    return count;
}

void
print_persons(person_t * p)
{
    for (int i = 0; p[i] != NULL; i++) {
        printf("name: %s, age: %d\n", PERSON_NAME(p[i]), PERSON_AGE(p[i]));
    }
}

int
main(int argc, char * argv[])
{
    person_t * persons = person_list();
    if (argc == 2) {
        char * name = argv[1];
        if (find_persons_by_name(persons, name)) {
            printf("Found %s\n", name);
        } else {
            printf("Not found %s\n", name);
        }
    } else if (argc > 2) {
        (void)rename_person(persons, argv[1], argv[2]);
        print_persons(persons);
    } else {
        print_persons(persons);
    }
    return 0;
}