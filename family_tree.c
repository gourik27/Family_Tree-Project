#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age)
{
    Person *p;
    p = malloc(sizeof(Person));
    if (p == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(p->name, name);
    p->age = age;
    p->father = NULL;
    p->mother = NULL;
    return p;
}

void read_person_info(const char *role, char *name_out, int *age_out)
{
    printf("Enter name of %s: ", role);
    fgets(name_out, 50, stdin);

    name_out[strcspn(name_out, "\n")] = '\0';  

    printf("Enter age of %s: ", role);
    scanf("%d", age_out);
    getchar();
}

int main()
{
    Person *people[7];
    char name[50];
    int age;

    read_person_info("Paternal Grandfather", name, &age);
    people[0] = create_person(name, age);

    read_person_info("Paternal Grandmother", name, &age);
    people[1] = create_person(name, age);

    read_person_info("Maternal Grandfather", name, &age);
    people[2] = create_person(name, age);

    read_person_info("Maternal Grandmother", name, &age);
    people[3] = create_person(name, age);

    read_person_info("Father", name, &age);
    people[4] = create_person(name, age);

    read_person_info("Mother", name, &age);
    people[5] = create_person(name, age);

    read_person_info("Yourself", name, &age);
    people[6] = create_person(name, age);

    printf("\nAll 7 family members have been entered successfully!\n");

    for (int i = 0; i < 7; i++)
    {
        free(people[i]);
    }
    return 0;
}