//
//  GameOverScene.hpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#ifndef GameOverScene_hpp
#define GameOverScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class GameOverScene:public Scene {
protected:
    
public:
    virtual bool init();
    static Scene* createScene();
    
    CREATE_FUNC(GameOverScene);
};

#endif /* GameOverScene_hpp */
