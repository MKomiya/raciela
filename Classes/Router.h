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
#include <dispatch/dispatch.h>
#include <stack>

namespace Raciela
{
    class State;
    class Router
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
        
    private:
        static Router* instance;
        std::stack<State*> state_stack;
    };
}

#endif /* defined(__raciela__Router__) */
