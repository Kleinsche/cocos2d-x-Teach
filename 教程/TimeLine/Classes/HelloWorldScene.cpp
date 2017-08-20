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
    
    
    
    auto node = CSLoader::createNode("res/MainScene.csb");
    addChild(node);
    
    //创建时间线
    auto time = CSLoader::createTimeline("res/MainScene.csb");
    time->gotoFrameAndPlay(0);
    node->runAction(time);
    
    //帧事件
    time->setFrameEventCallFunc([](cocostudio::timeline::Frame* frame){
        
        auto event = dynamic_cast<cocostudio::timeline::EventFrame*>(frame);
        
        if (event == nullptr) {
            return;
        }
        
        CCLOG("%s ",event->getEvent().c_str());
    });

    
    
    return true;
}
