#ifndef PERSON_DEFINE_H
#define PERSON_DEFINE_H

struct person
{
    unsigned int age;

    void (*say)(void* this);
};

typedef struct person Person;

#endif //PERSON_H