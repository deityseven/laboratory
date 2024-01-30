#include "singleton.struct"
#include "singleton.h"
#include <stdlib.h>
#include <stdio.h>

// Man_constructor
void Singleton_constructor_default(Singleton* this)
{
    this->var = 20;
}

// Man_new_constructor
Singleton* Singleton_new_constructor_default()
{
    Singleton* this = (Singleton*)malloc(sizeof(Singleton));
    Singleton_constructor_default(this);
    return this;
}

// Man_destructor
void Singleton_destructor(Singleton* this)
{
    free(this);
}

// Man_public
void Singleton_say(Singleton* this)
{
    printf("singleton.var = %d\n", this->var);
}

Singleton* Singleton_instance()
{
    static Singleton* ins = nullptr;
    if(ins == nullptr)
    {
        ins = Singleton_new_constructor_default();
    }
    
    return ins;
}