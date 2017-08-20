//
//  XmlScene.hpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/3.
//
//

#ifndef XmlScene_hpp
#define XmlScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <tinyxml2/tinyxml2.h>
#include <json/document.h>

USING_NS_CC;

class XmlScene:public Layer {
protected:
    
public:
    XmlScene();
    
    virtual ~XmlScene();
    
    virtual bool init();
    
    static Scene* createScene();
    
    
    CREATE_FUNC(XmlScene);
};

#endif /* XmlScene_hpp */
