#ifndef TEMPLATE_METHOD_H
#define TEMPLATE_METHOD_H

typedef struct abstract Abstract;

void Abstract_template_method(Abstract* this);

typedef struct concrete Concrete;

// Concrete_constructor
void Concrete_constructor_default(Concrete* this);

// Concrete_new_constructor
Concrete* Concrete_new_constructor_default();

// Concrete_destructor
void Concrete_destructor(Concrete* this);

// Virtual_method0
void virtualFunction0(Concrete* this);

// Virtual_method1
void virtualFunction1(Concrete* this);

#endif //TEMPLATE_METHOD_H