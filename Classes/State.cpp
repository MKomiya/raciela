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
    
    delegate();
    return true;
}

void State::delegate()
{
}