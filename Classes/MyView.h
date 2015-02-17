//
//  MyView.h
//  raciela
//
//  Created by S_Wyvern on 2015/02/17.
//
//

#ifndef __raciela__MyView__
#define __raciela__MyView__

#include <stdio.h>
#include "View.h"

class MyView : public Raciela::View
{
public:
    virtual bool init();
    CREATE_FUNC(MyView);
    
    void updateLabel(int count);
    
    CC_SYNTHESIZE_READONLY(cocos2d::MenuItemFont*, label, Label);
};

#endif /* defined(__raciela__MyView__) */
