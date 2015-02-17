//
//  Router.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "Router.h"

using namespace Raciela;

void Router::pushState(State *state)
{
    state_stack.push(state);
}

void Router::popState()
{
    state_stack.pop();
}