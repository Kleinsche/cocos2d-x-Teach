//
//  TableViewScene.cpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/2.
//
//

#include "TableViewScene.hpp"

TableViewScene::TableViewScene(){
    
};

TableViewScene::~TableViewScene(){
    
};

Scene* TableViewScene::createScene(){
    auto scene = Scene::create();
    auto layer = TableViewScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool TableViewScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    
    TableView *tableView = TableView::create(this, Size(100, 200));
    tableView->setPosition(Director::getInstance()->getVisibleSize()/2);
    tableView->setDelegate(this);
    addChild(tableView);
    
    return true;
}


Size TableViewScene::cellSizeForTable(TableView* table){
    return Size(100, 50);
}

TableViewCell* TableViewScene::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx){
    
    TableViewCell* cell = table->dequeueCell();
    Label* label;
    
    if (cell == NULL) {
        cell = TableViewCell::create();
        label = Label::create();
        label->setTag(2);
        label->setSystemFontSize(25);
        label->setAnchorPoint(Vec2(0, 0));
        cell->addChild(label);
    }else{
        label = (Label*)cell->getChildByTag(2);
    }
    
    label->setString(StringUtils::format("Label %ld",idx));
    
    return cell;
}


ssize_t TableViewScene::numberOfCellsInTableView(TableView *table){
    return 100;
}

void TableViewScene::tableCellTouched(TableView* table, TableViewCell* cell){
    
    Label* label = (Label*)cell->getChildByTag(2);
    CCLOG("%s ",label->getString().c_str());
    
}


