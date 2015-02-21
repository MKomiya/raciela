//
//  View.h
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#ifndef __raciela__View__
#define __raciela__View__

#include <stdio.h>
#include <cocos2d.h>

namespace Raciela
{
    class Dispatcher;
    class View : public cocos2d::Layer
    {
    public:
        virtual bool init();
        virtual void onChange();
        
    protected:
        Dispatcher* dispatcher;
    };
}

#endif /* defined(__raciela__View__) */
