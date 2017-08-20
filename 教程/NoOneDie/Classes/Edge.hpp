//
//  Edge.hpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Edge:public Node {
protected:
    
public:
    virtual bool init();
    CREATE_FUNC(Edge);
};

#endif /* Edge_hpp */
