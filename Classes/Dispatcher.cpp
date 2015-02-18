//
//  Dispatcher.cpp
//  raciela
//
//  Created by S_Wyvern on 2015/02/18.
//
//

#include "Dispatcher.h"

Raciela::Dispatcher* Raciela::Dispatcher::instance;

using namespace Raciela;
USING_NS_CC;

Listener::Listener(Callback callback)
{
    listener = [callback]() {
        if (callback != nullptr) {
            callback();
        }
    };
}

void Listener::onEvent()
{
    listener();
}

void Dispatcher::subscribe(std::string ev, Callback callback)
{
    auto it = listeners.find(ev);
    if (it != listeners.end()) {
        listeners.erase(it);
    }
    
    listeners.insert(std::make_pair(ev, new Listener(callback)));
}

void Dispatcher::dispose(std::string ev)
{
    auto it = listeners.find(ev);
    if (it == listeners.end()) {
        return ;
    }
    
    delete it->second;
    listeners.erase(it);
}

void Dispatcher::dispatch(std::string ev)
{
    auto it = listeners.find(ev);
    if (it != listeners.end()) {
        it->second->onEvent();
    }
}