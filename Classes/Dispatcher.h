//
//  Dispatcher.h
//  raciela
//
//  Created by S_Wyvern on 2015/02/18.
//
//

#ifndef __raciela__Dispatcher__
#define __raciela__Dispatcher__

#include <stdio.h>
#include <dispatch/dispatch.h>
#include <cocos2d.h>

namespace Raciela
{
    typedef const std::function<void ()>& Callback;
    
    class Listener : public cocos2d::Ref
    {
    public:
        Listener(Callback callback);
        static Listener* create(Callback callback);
        void onEvent();
        
    private:
        std::function<void ()> listener;
    };
    
    class Dispatcher
    {
    public:
        static Dispatcher* getInstance() {
            static dispatch_once_t token;
            dispatch_once(&token, ^{
                if (!instance) {
                    instance = new Dispatcher();
                }
            });
            return instance;
        }
        
        void subscribe(std::string ev, Callback callback);
        void dispose(std::string ev);
        void dispatch(std::string ev);
        
    private:
        static Dispatcher* instance;
        cocos2d::Map<std::string, Listener*> listeners;
    };
}

#endif /* defined(__raciela__Dispatcher__) */
