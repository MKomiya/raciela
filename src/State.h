//
//  State.h
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#ifndef __raciela__State__
#define __raciela__State__

#include <stdio.h>
#include <cocos2d.h>

namespace Raciela
{
    class View;
    class Dispatcher;
    class State : public cocos2d::Ref
    {
    public:
        virtual ~State();
        
        virtual bool init();
        virtual void delegate();
        
        virtual void enter(){};
        virtual void update(){};
        virtual void exit(){};
        
    protected:
        View* view;
        Dispatcher* dispatcher;
    };
}

#endif /* defined(__raciela__State__) */
