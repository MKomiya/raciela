//
//  MyView.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "MyView.h"
#include "Dispatcher.h"

using namespace Raciela;
USING_NS_CC;

bool MyView::init()
{
    if (!View::init()) {
        return false;
    }
    
    auto s = Director::getInstance()->getWinSize();
    label = MenuItemFont::create("count:0", [=](Ref *s) {
        dispatcher->dispatch("cnt:++");
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

bool MyNextView::init()
{
    if (!View::init()) {
        return false;
    }
    
    auto s = Director::getInstance()->getWinSize();
    l = Label::createWithSystemFont("hello world", "Arial", 24);
    l->setPosition(s.width / 2.0f, s.height / 2.0f);
    addChild(l);
    
    return true;
}

void MyNextView::updateLabel(std::string str)
{
    l->setString(str);
}