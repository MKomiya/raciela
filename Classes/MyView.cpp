//
//  MyView.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "MyView.h"

using namespace Raciela;
USING_NS_CC;

bool MyView::init()
{
    if (!View::init()) {
        return false;
    }
    
    auto s = Director::getInstance()->getWinSize();
    label = MenuItemFont::create("count:0", [=](Ref *s) {
        dispatcher->dispatchCustomEvent("cnt:++");
    });
    label->setPosition(s.width / 2.0f, s.height / 2.0f);
    auto menu = Menu::create(label, nullptr);
    menu->setPosition(Point::ZERO);
    addChild(menu);
    
    return true;
}

void MyView::updateLabel(int count)
{
    std::string result = "count:" + std::to_string(count);
    label->setString(result);
}