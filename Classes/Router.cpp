//
//  Router.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "Router.h"
#include "View.h"

using namespace Raciela;

Router* Router::instance;

Router::Router()
{
    root = cocos2d::Scene::create();
}

void Router::pushState(State *state)
{
    state_stack.pushBack(state);
}

void Router::popState()
{
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