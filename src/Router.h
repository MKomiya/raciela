//
//  Router.h
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#ifndef __raciela__Router__
#define __raciela__Router__

#include <stdio.h>
#include <cocos2d.h>
#include <dispatch/dispatch.h>

#include "State.h"

namespace Raciela
{
    class View;
    class Dispatcher;
    class Router : public cocos2d::Ref
    {
    public:
        static Router* getInstance() {
            static dispatch_once_t token;
            dispatch_once(&token, ^{
                if (!instance) {
                    instance = new Router();
                }
            });
            return instance;
        }
        
        void pushState(State *state);
        void popState();
        void replaceState(State *state);
        
        void update(float t);
        
    private:
        Router();
        Router(const Router&);
        ~Router();
        
        static Router* instance;
        cocos2d::Vector<State*> state_stack;
        Dispatcher* dispatcher;
    };
}

#endif /* defined(__raciela__Router__) */
