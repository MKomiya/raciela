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
    Router::getInstance()->addView(view);
    
    return true;
}

void MyState::delegate()
{
    State::delegate();
    
    dispatcher->addCustomEventListener("state:enter", [](Ref* s) {
        CCLOG("enter state");
    });
    dispatcher->addCustomEventListener("state:exit", [=](Ref* s) {
        CCLOG("exit state");
        Router::getInstance()->removeView(view);
    });

    dispatcher->addCustomEventListener("cnt:++", [=](EventCustom*) {
        count++;
        
        auto v = static_cast<MyView*>(view);
        v->updateLabel(count);
        
        if (count == 20) {
            auto router = Router::getInstance();
            router->popState();
            router->pushState(MyNextState::create());
        }
    });
}

bool MyNextState::init()
{
    if (!State::init()) {
        return false;
    }
    
    label = "happy transition state";
    
    view = MyNextView::create();
    Router::getInstance()->addView(view);
    
    auto v = static_cast<MyNextView*>(view);
    v->updateLabel(label);
    
    return true;
}

void MyNextState::delegate()
{
    State::delegate();
    
    dispatcher->addCustomEventListener("state:enter", [](Ref* s) {
        CCLOG("enter next state");
    });
    dispatcher->addCustomEventListener("state:exit", [=](Ref* s) {
        CCLOG("exit next state");
        Router::getInstance()->removeView(view);
    });
}