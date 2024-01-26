#include "person.h"
#include <stdio.h>
#include <stdlib.h>

struct person
{
    unsigned int age;
};

Person* Person_constructor_default()
{
    Person* this = (Person*)malloc(sizeof(struct person));
    this->age = 0;
    return this;
}

Person* Person_constructor_age(unsigned int age)
{
    Person* this = (Person*)malloc(sizeof(struct person));
    this->age = age;
    return this;
}

void Person_destructor(Person* this)
{
    free(this);
}

void Person_say(Person* this)
{
    printf("person say : age = %d\n", this->age);
}

unsigned int Person_age(Person* this)
{
    return this->age;
}

unsigned int Person_setAge(Person* this, unsigned int age)
{
    this->age = age;
}

void Person_eat(Person* this)
{
    printf("Person eat\n");
}