//
//  create_func.h
//  raciela
//
//  Created by S_Wyvern on 2015/04/05.
//
//

#ifndef raciela_create_func_h
#define raciela_create_func_h

template<class Derived>
struct create_func {
    template<class... Args>
    static Derived* create(Args&&... args) {
        auto ret = new Derived();
        if (ret && ret->init(std::forward<Args>(args)...)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }
};

#endif
