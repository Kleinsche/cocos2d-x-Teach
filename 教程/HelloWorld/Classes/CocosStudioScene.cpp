//
//  CocosStudioScene.cpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/4.
//
//

#include "CocosStudioScene.hpp"


CocosStudioScene::CocosStudioScene(){
    
}

CocosStudioScene::~CocosStudioScene(){
    
}

Scene* CocosStudioScene::createScene(){
    auto scene = Scene::create();
    auto layer = CocosStudioScene::create();
    scene->addChild(layer);
    return scene;
}

bool CocosStudioScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visiable = Director::getInstance()->getVisibleSize();
    
//    //异步加载图片
//    Director::getInstance()->getTextureCache()->addImageAsync("Plist.png", [this](Texture2D* texture){
//        CCLOG("加载成功...");
//        
//        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Plist.plist",texture);
//        
//        auto node = CSLoader::createNode("res/MainScene.csb");
//        addChild(node);
//
//        
//        auto pageView = node->getChildByName<ui::PageView*>("PageView");
//        auto leftButton = node->getChildByName<ui::Button*>("Button_Left");
//        auto rightButton = node->getChildByName<ui::Button*>("Button_Right");
//        auto levelNum = node->getChildByName<ui::TextAtlas*>("AtlasLabel_CurrentScene");
//        
//        pageView->addEventListener([levelNum,pageView](Ref* ref,cocos2d::ui::PageView::EventType type){
//            if ( type == ui::PageView::EventType::TURNING ) {
//                levelNum->setString(StringUtils::format("%ld/3",pageView->getCurrentPageIndex()));
//            }
//        });
//        
//        
//        leftButton->addClickEventListener([pageView](Ref* ref){
//            
//            auto index = pageView->getCurrentPageIndex();
//            index--;
//            if (index<0) {
//                return;
//            }
//            pageView->scrollToPage(index);
//            
//        });
//        
//        
//        rightButton->addClickEventListener([pageView](Ref* ref){
//            
//            auto index = pageView->getCurrentPageIndex();
//            index++;
//            if (index>2) {
//                return;
//            }
//            pageView->scrollToPage(index);
//            
//        });
//    });
    
    
    CCLOG("正在加载...");
    
    
    return true;
}
