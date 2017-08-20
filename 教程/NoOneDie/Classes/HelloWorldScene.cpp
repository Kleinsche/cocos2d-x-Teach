#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    
    auto scene = Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto bg = Sprite::create("paoku.png", Rect(Vec2(0, 0), visibleSize));
    bg->setTextureRect(Rect(Vec2(0, 0), Director::getInstance()->getVisibleSize()));
    bg->setPosition(visibleSize/2);
    addChild(bg);
   
    if ( !Layer::init() )
    {
        return false;
    }
    
    game.insert(0, GameController::creat(this, 30));
//    game.insert(0, GameController::creat(this, 130));
    
    
    
    auto jumpEvent = EventListenerTouchOneByOne::create();
    jumpEvent->onTouchBegan = [this](Touch* t,Event* e){
        
        for (auto it = game.begin(); it != game.end(); it++) {
            
            if ((*it)->hitTestPoint(t->getLocation())) {
                (*it)->onTouched();
                
                break;
            }
            
        }
        return false;
        
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(jumpEvent, this);
    
    
    
    
    
    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [this](PhysicsContact& contact){
        
            Director::getInstance()->replaceScene(GameOverScene::createScene());
            CCLOG("碰撞测试");
            unscheduleUpdate();
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    scheduleUpdate();
    return true;
}


void HelloWorld::update(float dt){
    
    for (auto it = game.begin();it != game.end() ; it++) {
        (*it)->onupdate();
    }
    
}
