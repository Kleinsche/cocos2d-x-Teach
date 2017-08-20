//
//  XmlScene.cpp
//  HelloWorld
//
//  Created by Kleinsche on 2017/7/3.
//
//

#include "XmlScene.hpp"

XmlScene::XmlScene(){
    
}

XmlScene::~XmlScene(){
    
}

Scene* XmlScene::createScene(){
    auto scene = Scene::create();
    auto layer = XmlScene::create();
    scene->addChild(layer);
    return scene;
}

bool XmlScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visiable = Director::getInstance()->getVisibleSize();
    
    /*
    auto doc = new tinyxml2::XMLDocument();
    doc->Parse(FileUtils::getInstance()->getStringFromFile("data.xml").c_str());
    auto root = doc->RootElement();
    
    for (auto e = root->FirstChildElement(); e; e = e->NextSiblingElement()) {
        
        std::string str;
        for (auto attr = e->FirstAttribute(); attr; attr = attr->Next()) {
            str+=attr->Name();
            str+=":";
            str+=attr->Value();
            str+=",";
        }
        
        CCLOG("%s ",str.c_str());
        
    }
    */
    
    ////////////////////////// Json //////////////////////////////
    /*
    rapidjson::Document d;
    d.Parse<0>(FileUtils::getInstance()->getStringFromFile("data.json").c_str());
    
    CCLOG("%s ",d[(int)1]["name"].GetString());
     */
    
    return true;
}
