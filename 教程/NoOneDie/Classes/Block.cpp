//
//  Block.cpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#include "Block.hpp"

bool Block::init(){
    if (!Sprite::init()) {
        return false;
    }
    
    auto size = Size(rand()%20+5, rand()%30+10);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    

    setTextureRect(Rect(0, 0, size.width, size.height));
    setColor(Color3B(0, 0, 0));
    setContentSize(size);
    
    setPosition(visibleSize.width, size.height/2);
    setPhysicsBody(PhysicsBody::createBox(getContentSize()));
    getPhysicsBody()->setDynamic(false);
    getPhysicsBody()->setContactTestBitmask(2);
    
    scheduleUpdate();
    
    
    
    return true;
}

void Block::update(float dt) {
    this->setPositionX(getPositionX()-3);
    
    if (this->getPosition().x < 0) {
        CCLOG("update");
        unscheduleUpdate();
        this->removeFromParent();
    }
}
