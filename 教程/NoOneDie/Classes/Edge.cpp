//
//  Edge.cpp
//  NoOneDie
//
//  Created by Kleinsche on 2017/7/7.
//
//

#include "Edge.hpp"

bool Edge::init(){
    
    if (!Node::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
    setPosition(visibleSize/2);
    
    return true;
}
