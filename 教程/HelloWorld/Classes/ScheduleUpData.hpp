//
//  ScheduleUpData.hpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/3.
//
//

#ifndef ScheduleUpData_hpp
#define ScheduleUpData_hpp

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class SchedulerUpData: public Layer {
protected:
    Label* label;
    
public:
    SchedulerUpData();
    
    virtual ~SchedulerUpData();
    
    virtual bool init();
    
    static Scene* createScene();
    
    
    CREATE_FUNC(SchedulerUpData);
    
public:
    virtual void updata(float dt);
    
    void scheduler(float f);
    
};

#endif /* ScheduleUpData_hpp */
