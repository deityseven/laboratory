#include "man.h"
#include "person.h"
#include "person_define.h"
#include <stdlib.h>
#include <stdio.h>

struct man
{
    Person super;
    const char* name;
};

void Man_constructor_default(Man* this)
{
    this->super.age = 10;
    this->super.say = Man_say;
    this->name = "__orz__";
}

Man* Man_new_constructor_default()
{
    Man* this = (Man*)malloc(sizeof(Man));
    this->super.age = 10;
    this->super.say = Man_say;
    this->name = "__orz__";

    return this;
}

void Man_destructor(Man* this)
{
    Person_destructor(&this->super);
    free(this);
}

void Man_say(Man* this)
{
    printf("Man age : %d, name : %s\n", Person_age(&this->super), this->name);
}

void Man_eat(Man* this)
{
    printf("Man eat\n");
}