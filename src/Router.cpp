//
//  Router.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "Router.h"
#include "View.h"
#include "Dispatcher.h"

using namespace Raciela;

Router* Router::instance;

Router::Router()
{
    root = cocos2d::Scene::create();
    dispatcher = Dispatcher::getInstance();
}

void Router::pushState(State *state)
{
    state_stack.pushBack(state);
    dispatcher->dispatch("state:enter");
    state->enter();
}

void Router::popState()
{
    auto state = state_stack.front();
    
    state->exit();
    dispatcher->dispatch("state:exit");
    state_stack.popBack();
}

void Router::addView(View *view)
{
    root->addChild(view);
}

void Router::removeView(View *view)
{
    root->removeChild(view);
}