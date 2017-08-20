//
//  GameOverScene.cpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#include "GameOverScene.hpp"
#include "HelloWorldScene.h"

bool GameOverScene::init(){
    if (!Scene::init()) {
        return false;
    }
    
    auto label = Label::create();
    label->setSystemFontSize(50);
    label->setString("Game Over!");
    label->setPosition(Director::getInstance()->getVisibleSize()/2);
    addChild(label);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* t,Event* e){
        Director::getInstance()->replaceScene(HelloWorld::createScene());
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

Scene* GameOverScene::createScene(){
    return GameOverScene::create();
}
