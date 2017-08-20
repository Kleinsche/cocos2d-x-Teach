//
//  TableViewScene.hpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/2.
//
//

#ifndef TableViewScene_hpp
#define TableViewScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TableViewScene:public Layer,TableViewDataSource,TableViewDelegate {
protected:
    
public:
    TableViewScene();
    
    virtual ~TableViewScene();
    
    static Scene* createScene();
    
    virtual bool init();
    
    
    CREATE_FUNC(TableViewScene);
    
public:
    
    virtual Size cellSizeForTable(TableView* table);
    
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
    
    virtual ssize_t numberOfCellsInTableView(TableView *table);
    
public:
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    
//    virtual void scrollViewDidScroll(ScrollView* view) {};
//    
//    virtual void scrollViewDidZoom(ScrollView* view) {};
    
    
};



#endif /* TableViewScene_hpp */
