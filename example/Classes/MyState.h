//
//  MyState.h
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#ifndef __raciela__MyState__
#define __raciela__MyState__

#include <stdio.h>
#include "State.h"

class MyView;
class MyNextView;
class MyState : public Raciela::State
{
public:
    CREATE_FUNC(MyState);
    virtual bool init() override;
    virtual void delegate() override;
    virtual void exit() override;
    
    CC_SYNTHESIZE_READONLY(MyView*, view, View);
    CC_SYNTHESIZE_READONLY(int, count, Count);
};

class MyNextState : public Raciela::State
{
public:
    CREATE_FUNC(MyNextState);
    virtual bool init() override;
    virtual void delegate() override;
    
    CC_SYNTHESIZE_READONLY(MyNextView*, view, View);
    CC_SYNTHESIZE_READONLY(std::string, label, Label);
};

#endif /* defined(__raciela__MyState__) */
