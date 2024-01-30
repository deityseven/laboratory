#ifndef SINGLETON_H
#define SINGLETON_H

typedef struct singleton Singleton;

// Singleton_instance
Singleton* Singleton_instance();

// Singleton_destructor
void Singleton_destructor(Singleton* this);

// Singleton_public
void Singleton_say(Singleton* this);

#endif //SINGLETON_H