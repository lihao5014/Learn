#include "animal.h"
#include <string.h>
#include <iostream>

using namespace std;

Animal::Animal()
{
    memset(m_array,0,sizeof(m_array));
    init();
}

void Animal::init()
{
    m_map[EAT] = &eat;
    m_map[DRINK] = drink;
    m_map[SLEEP] = &Animal::sleep;
    m_map[WALK] = Animal::walk;
    m_map[RUN] = static_cast<pFun>(&run);
    m_map[JUMP] = static_cast<pFun>(Animal::jump);
    
    m_array[EAT] = &eat;
    m_array[DRINK] = drink;
    m_array[SLEEP] = &Animal::sleep;
    m_array[WALK] = Animal::walk;
    m_array[RUN] = static_cast<pFun>(&run);
    m_array[JUMP] = static_cast<pFun>(Animal::jump);
}
    
void Animal::process(Action_t action)
{
    switch(action){
    case EAT:
        eat();
        break;
    case DRINK:
        drink();
        break;
    case SLEEP:
        sleep();
        break;
    case WALK:
        walk();
        break;
    case RUN:
        run();
        break;
    case JUMP:
        jump();
        break;
    default:
        cout<<"action ="<<static_cast<int>(action)<<" is ilegal!"<<endl;
    }
}

void Animal::handle(Action_t action)
{
    if(action == EAT){
        eat();
    }else if(action == DRINK){
        drink();
    }else if(action == SLEEP){
        sleep();
    }else if(action == WALK){
        walk();
    }else if(action == RUN){
        run(); 
    }else if(action == JUMP){
        jump();    
    }else{
        cout<<"action ="<<static_cast<int>(action)<<" is ilegal!"<<endl;
    }
}

void Animal::dispose(Action_t action)
{
    map<Action_t,pFun>::iterator iter = m_map.find(action);
    if(iter != m_map.end()){
        pFun pfun = iter->second;
        if(pfun != nullptr){
            (this->*pfun)();
        }
    }
}

void Animal::conduct(Action_t action)
{
    if(action >= EAT && action <= JUMP){
        pFun pfun = m_array[action];
        if(pfun != nullptr){
            (this->*pfun)();
        }
    }
}

void Animal::eat()
{
    cout<<"animal eat"<<endl;
}

void Animal::drink()
{
    cout<<"animal drink"<<endl;
}

void Animal::sleep()
{
    cout<<"animal sleep"<<endl;
}

void Animal::walk()
{
    cout<<"animal walk"<<endl;
}

void Animal::run()
{
    cout<<"animal run"<<endl;
}

void Animal::jump()
{
    cout<<"animal jump"<<endl;
}

void Animal::operator [](Action_t action)
{
    map<Action_t,pFun>::iterator iter = m_map.find(action);
    if(iter != m_map.end()){
        pFun pfun = iter->second;
        if(pfun != nullptr){
            (this->*pfun)();
        }
    } 
}

void Animal::operator ()(Action_t action)
{
    if(action >= EAT && action <= JUMP){
        pFun pfun = m_array[action];
        if(pfun != nullptr){
            (this->*pfun)();
        }
    }
}