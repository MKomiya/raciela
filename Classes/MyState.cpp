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
    
    dispatcher->addCustomEventListener("cnt:++", [=](EventCustom*) {
        count++;
        
        auto v = static_cast<MyView*>(view);
        v->updateLabel(count);
    });
}