#ifndef PERSON_H
#define PERSON_H

typedef struct person Person;

// Person_constructor
void Person_constructor_default(Person* this);
void Person_constructor_age(Person* this, unsigned int age);

// Person_new_constructor
Person* Person_new_constructor_default();
Person* Person_new_constructor_age(unsigned int age);

// Person_destructor
void Person_destructor(Person* this);

// Person_public
unsigned int Person_age(Person* this);
unsigned int Person_setAge(Person* this, unsigned int age);
void Person_say(Person* this);
void Person_eat(Person* this);

#endif //PERSON_H