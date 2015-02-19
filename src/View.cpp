//
//  View.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#include "View.h"
#include "Dispatcher.h"

using namespace Raciela;
USING_NS_CC;

bool View::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    dispatcher = Dispatcher::getInstance();
    return true;
}