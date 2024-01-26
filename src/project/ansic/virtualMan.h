#ifndef VIRTUAL_H
#define VIRTUAL_H

struct A
{
    void (*eat)(void*);
};

struct B
{
    struct A super;
};

void A_eat(struct A* this);

void B_eat(struct B* this);

#endif //VIRTUAL_H