//
//  State.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "State.h"
#include "Dispatcher.h"

using namespace Raciela;
USING_NS_CC;

State::~State()
{
}

bool State::init()
{
    dispatcher = Dispatcher::getInstance();
    
    delegate();
    return true;
}

void State::delegate()
{
}
