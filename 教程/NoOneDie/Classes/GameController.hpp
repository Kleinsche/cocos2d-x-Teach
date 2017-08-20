//
//  GameController.hpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Edge.hpp"
#include "Hero.hpp"
#include "Block.hpp"

USING_NS_CC;

class GameController:public Ref {
protected:
    Edge* edge;
    Hero* hero;
    Layer* _layer;
    float _positionY;
    Size visibleSize;
    int currentFrameIndex;
    int nextFrameCounts;
    
    void resetFrames();
    void addBlock();
    
public:
    virtual bool init(Layer* layer,float poitionY);
    static GameController* creat(Layer* layer,float poitionY);
    
    void onupdate();
    bool hitTestPoint(cocos2d::Vec2 vec);
    void onTouched();
};

#endif /* GameController_hpp */
