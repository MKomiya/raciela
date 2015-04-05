//
//  MyState.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "MyState.h"
#include "MyView.h"
#include "Router.h"
#include "Dispatcher.h"
#include "ViewManager.h"

using namespace Raciela;
USING_NS_CC;

bool MyState::init()
{
    if (!State::init()) {
        return false;
    }
    
    // init props
    count = 0;
    
    // init views
    view = MyView::create();
    ViewManager::getInstance()->addView(view);
    
    return true;
}

void MyState::delegate()
{
    State::delegate();
    
    dispatcher->subscribe<void()>("state:enter", []() {
        CCLOG("enter state");
    });
    dispatcher->subscribe<void()>("state:exit", [=]() {
        CCLOG("exit state");
    });

    dispatcher->subscribe<void()>("cnt:++", [=]() {
        count++;
        
        view->updateLabel(count);
        
        if (count == 20) {
            auto router = Router::getInstance();
            router->replaceState(MyNextState::create());
        }
    });
}

void MyState::exit()
{
    State::exit();
    ViewManager::getInstance()->removeView(view);
}

bool MyNextState::init()
{
    if (!State::init()) {
        return false;
    }
    
    label = "happy transition state";
    
    view = MyNextView::create();
    ViewManager::getInstance()->addView(view);
    
    view->updateLabel(label);
    
    return true;
}

void MyNextState::delegate()
{
    State::delegate();
    
    dispatcher->subscribe<void()>("state:enter", []() {
        CCLOG("enter next state");
    });
    dispatcher->subscribe<void()>("state:exit", [=]() {
        CCLOG("exit next state");
        ViewManager::getInstance()->removeView(view);
    });
}