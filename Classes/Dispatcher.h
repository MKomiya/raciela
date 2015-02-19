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
#include <unordered_map>
#include <cocos2d.h>

namespace Raciela
{
    class ListenerBase : public cocos2d::Ref
    {
    public:
        virtual ~ListenerBase() {};
    };
    
    template<typename T>
    class Listener final : public ListenerBase
    {
    public:
        inline Listener(const std::function<T> &func) : func(func) {};
        static Listener* create(const std::function<T> &func)
        {
            auto ret = new Listener<T>(func);
            if (ret) {
                ret->autorelease();
                return ret;
            }
            CC_SAFE_DELETE(ret);
            return nullptr;
        }
        
        template<typename... A>
        inline void onEvent(const A &...args) { func(args...); };
        
    private:
        const std::function<T> func;
    };
    
    class Dispatcher final
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
        
        template<typename T>
        void subscribe(std::string ev, const std::function<T> &callback)
        {
            auto it = listener_list.find(ev);
            if (it != listener_list.end()) {
                listener_list.erase(it);
            }
            auto f = Raciela::Listener<T>::create(callback);
            listener_list.insert(ev, f);
        }
        
        void dispose(std::string ev)
        {
            auto it = listener_list.find(ev);
            if (it == listener_list.end()) {
                return ;
            }
            
            listener_list.erase(it);
        }
        
        template<typename ...Ts>
        void dispatch(std::string ev, const Ts &...args)
        {
            auto it = listener_list.find(ev);
            if (it == listener_list.end()) {
                return;
            }
            
            auto f = dynamic_cast<Listener<void (Ts...)> *>(it->second);
            if (!f) {
                return ;
            }
            
            f->onEvent(args...);
        }
        
    private:
        inline Dispatcher() {};
        inline ~Dispatcher() {};
        
        static Dispatcher* instance;
        cocos2d::Map<std::string, ListenerBase*> listener_list;
    };
}

#endif /* defined(__raciela__Dispatcher__) */
