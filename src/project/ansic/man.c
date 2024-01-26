#include "man.h"
#include "person.h"
#include <stdlib.h>
#include <stdio.h>

struct man
{
    Person* super;
    const char* name;
};

Man* Man_constructor_default()
{
    Man* this = (Man*)malloc(sizeof(Man));
    this->super = Person_constructor_default();
    Person_setAge(this->super, 55);
    this->name = "__orz__";

    return this;
}

void Man_destructor(Man* this)
{
    Person_destructor(this->super);
    free(this);
}

void Man_say(Man* this)
{
    printf("Man age : %d, name : %s\n", Person_age(this->super), this->name);
}

void Man_eat(Man* this)
{
    printf("Man eat\n");
}