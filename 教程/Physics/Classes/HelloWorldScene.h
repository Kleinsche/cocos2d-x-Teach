#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
protected:
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    int EDGE_BIT_MASK   = 0b1000;
    int RED_BIT_MASK    = 0b0100;
    int GREEN_BIT_MASK  = 0b0010;
    int BLUE_BIT_MASK   = 0b0001;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    virtual void onEnter();
    
    void addEdges();
    
    void addBall(cocos2d::Vec2 vec);
};

#endif // __HELLOWORLD_SCENE_H__
