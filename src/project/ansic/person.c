#include "person.h"
#include "person_define.h"
#include <stdio.h>
#include <stdlib.h>

void Person_constructor_default(Person* this)
{
    this->age = 0;
    this->say = Person_say;
}

void Person_constructor_age(Person* this, unsigned int age)
{
    Person_constructor_default(this);
    this->age = age;
}

Person* Person_new_constructor_default()
{
    Person* this = (Person*)malloc(sizeof(struct person));
    Person_constructor_default(this);
    return this;
}

Person* Person_new_constructor_age(unsigned int age)
{
    Person* this = (Person*)malloc(sizeof(struct person));
    Person_constructor_age(this, age);
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