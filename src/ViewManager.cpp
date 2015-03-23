//
//  ViewManager.cpp
//  solno
//
//  Created by S_Wyvern on 2015/03/23.
//
//

#include "ViewManager.h"

using namespace Raciela;
USING_NS_CC;

ViewManager* ViewManager::instance;

ViewManager::ViewManager()
{
    root = Scene::create();
}

void ViewManager::addView(View *view)
{
    root->addChild(view);
}

void ViewManager::addView(View *view, int z_order)
{
    root->addChild(view, z_order);
}

void ViewManager::removeView(View *view)
{
    root->removeChild(view);
}

void ViewManager::playTransitionEffect(TransitionScene *scene)
{
    Director::getInstance()->replaceScene(scene);
    root = scene;
}