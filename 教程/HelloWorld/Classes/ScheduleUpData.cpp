//
//  ScheduleUpData.cpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/3.
//
//

#include "ScheduleUpData.hpp"

SchedulerUpData::SchedulerUpData(){
    
}

SchedulerUpData::~SchedulerUpData(){
    
}

bool SchedulerUpData::init(){
    if (!Layer::init()) {
        return false;
    }
    
    label = Label::create();
    label->setString("Hello");
    label->setSystemFontSize(50);
    addChild(label);
    
    
//    scheduleUpdate();
    schedule(schedule_selector(SchedulerUpData::scheduler), 1);
    
    return true;
}

Scene* SchedulerUpData::createScene(){
    auto scene = Scene::create();
    auto layer = SchedulerUpData::create();
    scene->addChild(layer);
    return scene;
}


void SchedulerUpData::updata(float dt){
    label->setPosition(label->getPosition()+Point(100,100));
    if (label->getPosition().x > Director::getInstance()->getVisibleSize().width || label->getPosition().y > Director::getInstance()->getVisibleSize().height) {
        unscheduleUpdate();
    }
    
}

void SchedulerUpData::scheduler(float f){
    label->setPosition(label->getPosition()+Vec2(100,100));
    CCLOG("<<<<");
}
