//
//  Block.hpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Block:public Sprite {
protected:
    
public:
    virtual bool init();
    CREATE_FUNC(Block);
    
    void update(float dt);
};

#endif /* Block_hpp */
