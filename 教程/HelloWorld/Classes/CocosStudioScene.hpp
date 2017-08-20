//
//  CocosStudioScene.hpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/4.
//
//

#ifndef CocosStudioScene_hpp
#define CocosStudioScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class CocosStudioScene:public Layer {
protected:
    
public:
    CocosStudioScene();
    
    virtual ~CocosStudioScene();
    
    virtual bool init();
    
    static Scene* createScene();
    
    
    CREATE_FUNC(CocosStudioScene);
};

#endif /* CocosStudioScene_hpp */
