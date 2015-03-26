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

bool State::init()
{
    dispatcher = Dispatcher::getInstance();
    return true;
}

void State::enter()
{
    delegate();
}

void State::resume()
{
    delegate();
}

void State::exit()
{
    dispatcher->removeAllListener();
}

void State::pause()
{
    dispatcher->removeAllListener();
}