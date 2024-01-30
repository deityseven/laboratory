#include "template-method.struct"
#include "template-method.h"
#include <stdlib.h>
#include <stdio.h>

void Abstract_template_method(Abstract* this)
{
    this->virtualFunction0(this);
    this->virtualFunction1(this);
}

// Virtual_method0
void virtualFunction0(Concrete* this)
{
    printf("Concrete virtualFunction0...var = %d\n", this->var);
}

// Virtual_method1
void virtualFunction1(Concrete* this)
{
    printf("Concrete virtualFunction1...var = %d\n", this->var);
}

// Concrete_constructor
void Concrete_constructor_default(Concrete* this)
{
    this->super.virtualFunction0 = (virtualFunction)virtualFunction0;
    this->super.virtualFunction1 = (virtualFunction)virtualFunction1;
    this->var = 80;
}

// Concrete_new_constructor
Concrete* Concrete_new_constructor_default()
{
    Concrete* this = (Concrete*)malloc(sizeof(Concrete));
    Concrete_constructor_default(this);
    return this;
}

// Concrete_destructor
void Concrete_destructor(Concrete* this)
{
    free(this);
}