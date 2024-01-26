#include <stdio.h>
#include "person.h"
#include "man.h"
#include "virtualMan.h"

void testPerson()
{
    Person* p = Person_constructor_age(80);
    Person_say(p);
    Person_destructor(p);
}

void testMan()
{
    Man* man = Man_constructor_default();
    Man_say(man);
    Man_destructor(man);
}

void testVirtual()
{
    struct B b;
    b.super.eat = B_eat;
    b.super.eat(&b);
}

int main(int argc, char *argv[])
{
    testVirtual();
	return 0;
}