//
//  GameController.cpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#include "GameController.hpp"



bool GameController::init(Layer* layer,float poitionY){
    
    _layer = layer;
    _positionY = poitionY;
    visibleSize = Director::getInstance()->getVisibleSize();
    
    //添加边框
    edge = Edge::create();
    edge->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 +poitionY));
//    edge->setContentSize(visibleSize);
    layer->addChild(edge);
    
    //添加地板
    auto floor = Sprite::create();
    floor->setColor(Color3B(0, 0, 0));
    floor->setTextureRect(Rect(0, 0, visibleSize.width, 3));
    floor->setPosition(visibleSize.width/2, 1.5 +poitionY);
    layer->addChild(floor);
    
    //添加角色
    hero = Hero::create();
    hero->setPosition(Vec2(25, hero->getContentSize().height +poitionY));
    layer->addChild(hero);
    
    
    resetFrames();
    return true;
}

GameController* GameController::creat(Layer* layer,float poitionY){
    
    auto _ins = new GameController();
    _ins->init(layer, poitionY);
    _ins->autorelease();
    return _ins;
}


void GameController::onupdate(){
    
    currentFrameIndex++;
//    CCLOG("%d %d",currentFrameIndex,nextFrameCounts);
    if (currentFrameIndex >= nextFrameCounts) {
        resetFrames();
        addBlock();
    }
    
}


void GameController::resetFrames(){
    
    currentFrameIndex = 0;
    nextFrameCounts = rand()%120 +60;
}

void GameController::addBlock(){
    auto b = Block::create();
    b->setPositionY(b->getContentSize().height/2 +_positionY);
    _layer->addChild(b);
}

bool GameController::hitTestPoint(Vec2 vec){
    CCLOG("hitTestPoint");
    return !edge->getBoundingBox().containsPoint(vec);
}

void GameController::onTouched(){
    CCLOG("onTouched");
    hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}
