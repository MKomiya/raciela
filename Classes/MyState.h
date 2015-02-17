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

class MyState : public Raciela::State
{
public:
    CREATE_FUNC(MyState);
    virtual bool init() override;
    virtual void delegate() override;
    
    CC_SYNTHESIZE_READONLY(int, count, Count);
};

#endif /* defined(__raciela__MyState__) */
