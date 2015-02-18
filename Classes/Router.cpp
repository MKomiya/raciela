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
    dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
}

void Router::pushState(State *state)
{
    state_stack.pushBack(state);
    dispatcher->dispatchCustomEvent("state:enter");
}

void Router::popState()
{
    dispatcher->dispatchCustomEvent("state:exit");
    dispatcher->dispatchCustomEvent("reset:subscribe");
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