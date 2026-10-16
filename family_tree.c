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

int main()
{
    Person *me;
    me = create_person("Student", 19);
    printf("Person created successfully!\n");
    printf("Name: %s\n", me->name);
    printf("Age: %d\n", me->age);
    free(me);
    return 0;
}