//
//  Hero.cpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/6.
//
//

#include "Hero.hpp"


Hero::Hero(){
    
}

Hero::~Hero(){
    
}

bool Hero::init(){
    
    if (!Sprite::init()) {
        return false;
    }
    
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("LuoLi.plist");
    
    Vector<SpriteFrame*> vect;
    char szName[100] = {0};
    
    for (int i = 1; i<=8; i++) {
        sprintf(szName, "s_%d.png", i);
        auto push = cache->getSpriteFrameByName(szName);
        vect.pushBack(push);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(vect,0.2f);
    Animate* animate = Animate::create(animation);
    
    runAction(RepeatForever::create(animate));

    

    
    setContentSize(Size(50, 63));
    setPhysicsBody(PhysicsBody::createBox(getContentSize()));
    getPhysicsBody()->setRotationEnable(false);
    setPosition(Vec2(25, 31.5));
    getPhysicsBody()->setContactTestBitmask(1);
    
    return true;
}
