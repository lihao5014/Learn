#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <map>

#define SIZE 6

enum Action_t
{
    EAT = 0,
    DRINK,
    SLEEP,
    WALK,
    RUN,
    JUMP,
};

class Animal
{
    typedef void (Animal::*pFun)();
public:    
    Animal();
    
    void process(Action_t action);
    void handle(Action_t action);
    void dispose(Action_t action);
    void conduct(Action_t action);
    
    void eat();
    void drink();
    void sleep();
    void walk();
    void run();
    void jump();
    
    void operator [](Action_t action);
    void operator ()(Action_t action);
private:
    void init();
    
    std::map<Action_t,pFun> m_map;
    pFun m_array[SIZE];
};


#endif //_ANIMAL_H