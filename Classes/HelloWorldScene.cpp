#include "HelloWorldScene.h"

#include "Router.h"
#include "MyState.h"
#include "MyView.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto router = Raciela::Router::getInstance();
    router->pushState(MyState::create());
    
    return scene;
}