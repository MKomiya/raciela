//
//  ViewManager.h
//  solno
//
//  Created by S_Wyvern on 2015/03/23.
//
//

#ifndef __solno__ViewManager__
#define __solno__ViewManager__

#include <stdio.h>
#include <cocos2d.h>
#include <dispatch/dispatch.h>

#include "View.h"

namespace Raciela
{
    class ViewManager : public cocos2d::Ref
    {
    public:
        static ViewManager* getInstance() {
            static dispatch_once_t token;
            dispatch_once(&token, ^{
                if (!instance) {
                    instance = new ViewManager();
                }
            });
            return instance;
        }
        
        void addView(View* view);
        void addView(View* view, int z_order);
        void removeView(View* view);
        
        void playTransitionEffect(cocos2d::TransitionScene* scene);
        
        CC_SYNTHESIZE(cocos2d::Scene*, root, RootScene);
        
    private:
        ViewManager();
        ViewManager(const ViewManager&);
        
        static ViewManager* instance;
    };
}

#endif /* defined(__solno__ViewManager__) */
