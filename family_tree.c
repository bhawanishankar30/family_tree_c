#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person *create_person(const char *name, int age)
{
    Person *p = malloc(sizeof(Person));

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(p->name, name);
    p->age = age;
    p->father = NULL;
    p->mother = NULL;

    return p;
}
void read_person_info(const char *role, char *name, int *age)
{
printf("Enter name of your %s: ", role);
scanf(" %49[^\n]", name);

printf("Enter age of your %s: ", role);  
scanf("%d", age);
}

int main()
{
char name[50];
int age;

Person *people[7];

const char *roles[7] = {  
    "Paternal Grandfather",  
    "Paternal Grandmother",  
    "Maternal Grandfather",  
    "Maternal Grandmother",  
    "Father",  
    "Mother",  
    "Yourself" 
    };
for (int i = 0; i < 7; i++) {  
    printf("\n");  
    read_person_info(roles[i], name, &age);  
    people[i] = create_person(name, age);  
}

}
