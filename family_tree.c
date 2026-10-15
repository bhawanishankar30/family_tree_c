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
void link_parents(Person *child, Person *father, Person *mother)
{
child->father = father;
child->mother = mother;
}
void print_family_relationships(const Person *me)
{
printf("\n=== FAMILY TREE RELATIONSHIPS ===\n\n");

printf("1. YOURSELF:\n");  
printf("   - Name: %s | Age: %d\n\n", me->name, me->age);

printf("2. PARENTS:\n");  
printf("   - Father: %s | Age: %d\n", me->father->name,  
       me->father->age);  
printf("   - Mother: %s | Age: %d\n\n", me->mother->name,  
       me->mother->age);

printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");  
printf("   - Grandfather: %s | Age: %d\n",  
       me->father->father->name, me->father->father->age);  
printf("   - Grandmother: %s | Age: %d\n\n",  
       me->father->mother->name, me->father->mother->age);

printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");  
printf("   - Grandfather: %s | Age: %d\n",  
       me->mother->father->name, me->mother->father->age);  
printf("   - Grandmother: %s | Age: %d\n",  
       me->mother->mother->name, me->mother->mother->age);
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
link_parents(people[4], people[0], people[1]);  
link_parents(people[5], people[2], people[3]);  
link_parents(people[6], people[4], people[5]);

print_family_relationships(people[6]);

}
