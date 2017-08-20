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
    
    /*
    auto av = experimental::ui::VideoPlayer::create();
    av->setContentSize(Director::getInstance()->getVisibleSize());
    av->setPosition(Director::getInstance()->getVisibleSize()/2);
    av->setFileName("love.mp4");
    av->play();
    addChild(av);
     */
    
    auto webView = experimental::ui::WebView::create();
    webView->setPosition(Director::getInstance()->getVisibleSize()/2);
    webView->setContentSize(Director::getInstance()->getVisibleSize());
    webView->loadURL("http://baidu.com");
    addChild(webView);

    return true;
}
