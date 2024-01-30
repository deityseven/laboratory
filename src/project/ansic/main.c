#include <stdio.h>
//#include "person.h"
#include "man.h"
#include "singleton.h"
#include "template-method.h"

void testPerson()
{
    Person* p = Person_new_constructor_age(80);
    Person_say(p);
    Person_destructor(p);
}

void testMan()
{
    Man* man = Man_new_constructor_default();
    Man_say(man);
    Man_destructor(man);
}

void testVirtual()
{
    Man* m = Man_new_constructor_default();
    Person_say((Person*)m);
}

int* staticVariable()
{
    static int a;
    printf("a = %d\n", &a);
    return &a;
}

void testStatic()
{
    int* b = staticVariable();
    printf("b = %d\n", b);
    b = staticVariable();
    printf("b = %d\n", b);
}

void testSingleton()
{
    Singleton* ins = Singleton_instance();
    Singleton_say(ins);
    Singleton* ins2 = Singleton_instance();
    Singleton_say(ins2);
    printf("ins = %d, ins2 = %d\n", ins, ins2);
}

void testTemplateMethod()
{
    Abstract* ins = (Abstract*)Concrete_new_constructor_default();
    Abstract_template_method(ins);
}
int main(int argc, char *argv[])
{
    //testVirtual();
    //testSingleton();
    testTemplateMethod();

	return 0;
}