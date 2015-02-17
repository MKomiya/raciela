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
    class View : public cocos2d::Layer
    {
    public:
        virtual bool init();
        
    protected:
        cocos2d::EventDispatcher* dispatcher;
    };
}

#endif /* defined(__raciela__View__) */
