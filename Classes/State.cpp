//
//  State.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "State.h"

using namespace Raciela;
USING_NS_CC;

State::~State()
{
}

bool State::init()
{
    view = nullptr;
    dispatcher = Director::getInstance()->getEventDispatcher();
    
    listener_enter = listener_exit = nullptr;
    
    delegate();
    return true;
}

void State::delegate()
{
    dispatcher->addCustomEventListener("reset:subscribe", [=](Ref* s) {
        CCLOG("reset subscribe");
        
        dispatcher->removeEventListener(listener_enter);
        dispatcher->removeEventListener(listener_exit);
        
        listener_enter->release();
        listener_exit->release();
    });
}