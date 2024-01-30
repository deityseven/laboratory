#ifndef MAN_H
#define MAN_H

#include "person.h"

typedef struct man Man;

// Man_constructor
void Man_constructor_default(Man* this);

// Man_new_constructor
Man* Man_new_constructor_default();

// Man_destructor
void Man_destructor(Man* this);

// Man_public
void Man_say(Man* this);

//virtual
void Man_eat(Man* this);

#endif //MAN_H