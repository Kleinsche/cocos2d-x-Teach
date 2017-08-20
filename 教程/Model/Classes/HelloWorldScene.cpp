#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    //////////////////// 自定义事件 /////////////////////////////
    
//     auto listener = EventListenerCustom::create("CustomEvent", CC_CALLBACK_1(HelloWorld::listen, this));
//     Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1/*优先级*/);
//    
//    //    //任何地方调用
//    //    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("CustomEvent");
//    
//    EventCustom e("CustomEvent");
//    e.setUserData((void*)"123");
//    
//    Director::getInstance()->getEventDispatcher()->dispatchEvent(&e);
//
    _direction.set(random(-1.0f,1.0f), random(-1.0f,1.0f));//随机
    auto dot = DrawNode::create();
    dot->drawDot(Vec2(0, 0), 10, Color4F(0.5, 1, 1, 1));
    addChild(dot);
    dot->setPosition(visibleSize/2);
    schedule([dot,this,visibleSize](float f){
        auto p = dot->getPosition();
        
        if (p.x < 0 || p.x > visibleSize.width) {
            _direction.x*=-1;
        }else if (p.y < 0 || p.y > visibleSize.height) {
            _direction.y*=-1;
        }
        
        dot->setPosition(p+_direction*10);
    }, "Test");
    
    return true;
}


//事件回调机制
void HelloWorld::listen(EventCustom* e){
    CCLOG("自定义事件%s ",(char*)(e->getUserData()));
}
