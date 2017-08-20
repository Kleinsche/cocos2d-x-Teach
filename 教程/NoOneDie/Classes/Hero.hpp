//
//  Hero.hpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/6.
//
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Hero:public Sprite {
protected:
    
    
public:
    Hero();
    virtual ~Hero();
    virtual bool init();
    CREATE_FUNC(Hero);
};

#endif /* Hero_hpp */
