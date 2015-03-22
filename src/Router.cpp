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
    if (!state_stack.empty()) {
        auto prev = state_stack.back();
        prev->pause();
    }
    
    state_stack.pushBack(state);
    state->enter();
}

void Router::popState()
{
    auto state = state_stack.back();
    
    state->exit();
    state_stack.popBack();
    
    if (!state_stack.empty()) {
        auto next = state_stack.back();
        next->resume();
    }
}

void Router::replaceState(State *state)
{
    if (state_stack.empty()) {
        return ;
    }
    
    auto prev = state_stack.back();
    prev->exit();
    state_stack.popBack();
    
    state_stack.pushBack(state);
    state->enter();
}

void Router::addView(View *view)
{
    root->addChild(view);
}

void Router::removeView(View *view)
{
    root->removeChild(view);
}

void Router::update(float t)
{
    if (!state_stack.empty()) {
        auto state = state_stack.back();
        state->update();
    }
}