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
    
    //异步加载图片
    Director::getInstance()->getTextureCache()->addImageAsync("Plist.png", [this](Texture2D* texture){
        CCLOG("加载成功...");
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Plist.plist",texture);
        
        auto node = CSLoader::createNode("MainScene.csb");
        addChild(node);
        
        //获取声音节点
//        auto audio = node->getChildByName("Audio");
//        //获取声音主键
//        auto a = (cocostudio::ComAudio*)audio->getComponent("Audio");
        
        auto pageView = node->getChildByName<ui::PageView*>("PageView");
        auto leftButton = node->getChildByName<ui::Button*>("Button_Left");
        auto rightButton = node->getChildByName<ui::Button*>("Button_Right");
        auto levelNum = node->getChildByName<ui::TextAtlas*>("AtlasLabel_CurrentScene");
        
        pageView->addEventListener([levelNum,pageView](Ref* ref,ui::PageView::EventType type){
            if (type == ui::PageView::EventType::TURNING) {
                levelNum->setString(StringUtils::format("%ld/3",pageView->getCurrentPageIndex()+1));
                CCLOG("<<<");
            }
        });
        
        
        
        leftButton->addClickEventListener([levelNum,pageView](Ref* ref){
            
            auto index = pageView->getCurrentPageIndex();
            index--;
            if (index<0) {
                return;
            }
            pageView->scrollToPage(index);
        });
        
        
        rightButton->addClickEventListener([pageView](Ref* ref){
            
            auto index = pageView->getCurrentPageIndex();
            index++;
            if (index>2) {
                return;
            }
            pageView->scrollToPage(index);
            
        });
    });
    
    
    CCLOG("正在加载...");


    return true;
}
