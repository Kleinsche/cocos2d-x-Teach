#include "CocosStudioScene.hpp"
#include "HelloWorldScene.h"

//#include <sstream>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 
    ////////////// 2D笛卡尔坐标系 /////////////////////////////////////////////////////////
    /*
    //正方形
    auto rect = DrawNode::create();
    rect->drawRect(Vec2(0, 0), Vec2(100, 100), Color4F(1, 0, 0, 1));
    addChild(rect);
    
    //点
    auto dot = DrawNode::create();
    dot->drawDot(Vec2(0, 0), 10, Color4F(1.0, 1.0, 1.0, 1.0));
    
    rect->setPosition(visibleSize/2);
    rect->addChild(dot);
    dot->setPosition(0, 0);//本地空间
    
    //固定位置
    rect->setContentSize(Size(100, 100));
    rect->setAnchorPoint(Vec2(0.5, 0.5));//设置锚点0~1
    
    schedule([dot,rect](float f){
     //旋转
        rect->setRotation(rect->getRotation()+1);
        //世界化本地坐标
        auto p = dot->convertToWorldSpace(Vec2(0, 0));
        CCLOG("%f,%f",p.x,p.y);
    }, "Test");
    */
    
    ///////////// 三角函数 //////////////////////////////////////////////////////////
    /*
    _angle = 0;
    
    auto dot = DrawNode::create();
    dot->drawDot(Vec2(100, 100), 10, Color4F(0.5, 1, 1, 1));
    addChild(dot);
    dot->setPosition(visibleSize/2);
    schedule([this](float f){
        //控制Y轴
        dot->setPositionY(cos(_angle)*100.0);
        //控制X轴
        dot->setPositionX(sin(_angle)*100.0);
        _angle+=0.1;
    }, "Test");
     */
    
    ////////////// 向量 /////////////////////////////////////////////////////////
    /*
//    CCRANDOM_0_1()
    _direction.set(random(-1.0f,1.0f), random(-1.0f,1.0f));//随机
    auto dot = DrawNode::create();
    dot->drawDot(Vec2(0, 0), 10, Color4F(0.5, 1, 1, 1));
    addChild(dot);
    dot->setPosition(visibleSize/2);
    schedule([dot,this,visibleSize](float f){
        auto p = dot->getPosition();
        
        if (p.x < 0 || p.x > visibleSize.width) {
            _direction.x*=-1;
        }else if (p.y < 0 || p.y > visibleSize.height) {
            _direction.y*=-1;
        }
        
        dot->setPosition(p+_direction*10);
    }, "Test");
    */
    
    ////////////// 显示对象 /////////////////////////////////////////////////////////
    /*
//    auto logo = Sprite::create("logo.jpg");
    
    //获取纹理
    auto img = Director::getInstance()->getTextureCache()->addImage("logo.jpg");
    //获取纹理大小
    auto logoSize = img->getContentSize();
    CCLOG("%f,%f",logoSize.width,logoSize.height);
    
    auto logo = Sprite::createWithTexture(img);
    logo->setPosition(visibleSize/2);
    addChild(logo);
    */
    /*
    //加载图层
    auto layer1 = Layer::create();
    layer1->setContentSize(visibleSize);
    
    std::stringstream ss;
    ss<<"layer"<<1<<".jpg";
    auto img1 = Sprite::create(ss.str());
    img1->setAnchorPoint(Vec2(0, 0));
    img1->setContentSize(layer1->getContentSize());
    
    layer1->addChild(img1);
    addChild(layer1);

    //跳转新场景
    scheduleOnce([visibleSize](float f){
        //创建场景
        auto scene2 = Scene::create();
        auto layer2 = Layer::create();
        layer2->setContentSize(visibleSize);
        auto img2 = Sprite::create("layer2.jpg");
        img2->setContentSize(layer2->getContentSize());
        img2->setAnchorPoint(Vec2(0, 0));
        
        layer2->addChild(img2);
        scene2->addChild(layer2);
        
        //替换场景
        Director::getInstance()->replaceScene(scene2);
    }, 3, "test");
    */
    
    ////////////// Action /////////////////////////////////////////////////////////
    /*
    auto role = Sprite::create("role.png");
    role->setPosition(visibleSize/2);
    role->setScale(0.5);//缩放
    addChild(role);
    
    //同时动作
    auto move1 = MoveTo::create(3, Vec2(visibleSize.width-200, visibleSize.height/2));
    auto move2 =ScaleTo::create(4, 1.5);
//    role->runAction(Spawn::create(move1,move2, NULL));
    
    //顺序动作
//    auto move1 = MoveBy::create(5, Vec2(500, 0));//向右移动500
//    auto move2 = move1->reverse();//反转
//    role->runAction(Sequence::create(move1,move2, NULL));
    
    //回调函数
    role->runAction(Sequence::create(Spawn::create(move1,move2, NULL),CallFunc::create([](){
        CCLOG("完成");
    }), NULL));
     */
    
    ////////////// Action特效 /////////////////////////////////////////////////////////
    /*
    auto role = NodeGrid::create();
    role->addChild(Sprite::create("role.png"));
    role->setPosition(visibleSize/2);
    addChild(role);
    
//    role->runAction(Twirl::create(5, Size(10, 10), Vec2(0, 0), 1, 1));
    
    auto w1 = Waves3D::create(5, Size(15, 10), 5, 40);
     //恢复初始状态
    auto w2 = Waves3D::create(5, Size(15, 10), 5, 0);
    role->runAction(Sequence::create(w1,w2, NULL));
    */
    
    ////////////// 场景切换特效 /////////////////////////////////////////////////////////
    /*
    auto background = Sprite::create("layer1.jpg");
    background->setPosition(visibleSize/2);
    background->setContentSize(visibleSize);
    addChild(background);
    
    scheduleOnce([visibleSize](float f){
        auto scene = Scene::create();
        auto layer = Layer::create();
        layer->setContentSize(visibleSize);
        auto bg = Sprite::create("layer2.jpg");
        bg->setContentSize(visibleSize);
        bg->setPosition(visibleSize/2);
        layer->addChild(bg);
        scene->addChild(layer);
        
        auto transition = TransitionSlideInB::create(1, scene);
        Director::getInstance()->replaceScene(transition);
    }, 2,"test");
    */
    
    ////////////// Ref内存管理 /////////////////////////////////////////////////////////
    /*
    auto icon = Sprite::create("CloseSelected.png");
    icon->setPosition(visibleSize/2);
//    addChild(icon);
    
    auto size = icon->getContentSize();
    CCLOG("%f,%f",size.height,size.width);
    
    schedule([icon](float f){
        auto size = icon->getContentSize();
        CCLOG("%f,%f",size.height,size.width);
    }, "test");
    
    icon->retain();
     */
    
    ////////////// Vector和Map ///////////////////////////////////////////////////
    /*
    Vector<Label*> vec;
     
    auto label1 = Label::create();
    label1->setString("Label 1");
    label1->setSystemFontSize(50);
    
    auto label2 = Label::create();
    label2->setString("Label 2");
    label2->setSystemFontSize(50);
    
    vec.pushBack(label1);
    vec.pushBack(label2);
    
    int i=0;
    for (auto label:vec) {
        i++;
        label->setPosition(Vec2(visibleSize.width/2, i*300));
        addChild(label);
    }
     */
    
    /*
    Map<std::string, Label*> map;
    
    auto label1 = Label::create();
    label1->setString("Label 1");
    label1->setSystemFontSize(50);
    label1->setPosition(Vec2(visibleSize.width/2, 200));
    
    auto label2 = Label::create();
    label2->setString("Label 2");
    label2->setSystemFontSize(50);
    label2->setPosition(Vec2(visibleSize.width/2, 400));
    
    map.insert("label1", label1);
    map.insert("label2", label2);
    
    
    addChild(map.at("label1"));
    */
    
    ////////////// Value ///////////////////////////////////////////////////
    /*
    Value value1 = Value("abc");
    Value value2 = Value(123);
    Value value3 = Value(true);
    
    CCLOG("%s %d %s",value1.asString().c_str(),value2.asInt(),value3.asBool()?"是":"否");
    CCLOG("%s %s %s",value1.asString().c_str(),value2.asString().c_str(),value3.asBool()?"是":"否");
    
    Value value4 = Value::Null;
    value4 = value1;
    value4 = value2;
    value4 = value3;
    
    CCLOG("%s %s",value4.asString().c_str(),value4.getType()==Value::Type::BOOLEAN?"是":"否");
    
    
    ValueVector vector;
    vector.push_back(Value("Hello"));
    vector.push_back(value1);
    vector.push_back(value2);
    for (auto v:vector) {
        CCLOG("%s",v.asString().c_str());
    }
    
    
    ValueMap map;
    map["a"] = value1;
    map["b"] = value2;
    for (auto m:map) {
        CCLOG("%s = %s",m.first.c_str(),m.second.asString().c_str());
    }
     */
    
    ////////////// MessageBox ///////////////////////////////////////////////////
    /*
    MessageBox("消息内容", "消息标题");
    */
    
    ////////////// TextField TTF ///////////////////////////////////////////////////
    /*
    TextFieldTTF* tf = TextFieldTTF::textFieldWithPlaceHolder("请在这里输入内容", "黑体", 50);
    tf->setPosition(visibleSize/2);
    addChild(tf);
    
    //设置监听器
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [tf](Touch* touch,Event* event){
        
        if (tf->getBoundingBox().containsPoint(touch->getLocation())) {
            tf->attachWithIME();
        }else{
            tf->detachWithIME();
        }
        
        return false;
    };
    
    //绑定监听器
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, tf);
    */
    
    ////////////// Menu ///////////////////////////////////////////////////
    /*
    auto menu = Menu::create(MenuItemImage::create("play.png", "pause.png", [](Ref*){
        CCLOG("aaa");
    }), NULL);
    addChild(menu);
     */
    
    ////////////// TableView ///////////////////////////////////////////////////
    /*
    auto tv = TableViewScene::create();
    addChild(tv);
    */
    
    ////////////// 帧动画 ///////////////////////////////////////////////////
    /*
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("add_move.plist");
    
     Vector<SpriteFrame*> vect;
    char szName[100] = {0};
//    memset(szName, 0, 9);
    
    for (int i = 0; i<=9; i++) {
        sprintf(szName, "add_move%04d", i);
        auto push = cache->getSpriteFrameByName(szName);
        vect.pushBack(push);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(vect,0.5f);
    Animate* animate = Animate::create(animation);
    
    auto sprite = Sprite::create();
    sprite->setPosition(visibleSize/2);
    addChild(sprite);
    sprite->runAction(RepeatForever::create(animate));
    */
    
    ////////////// 事件传递 ///////////////////////////////////////////////////
    /*
    auto label = Label::create();
    label->setString("Hello");
    label->setSystemFontSize(50);
    label->setPosition(visibleSize/2);
    addChild(label);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [label](Touch* t,Event* e){
        if (label->getBoundingBox().containsPoint(t->getLocation())) {
            CCLOG("<<<<");
        }
        return true;
    };
    listener->onTouchMoved = [](Touch* t,Event* e){
        CCLOG("%f %f\n",t->getLocation().x,t->getLocation().y);
    };
    listener->onTouchEnded = [](Touch* t,Event* e){
        CCLOG("onTouchEnded");
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, label);
     */
    
    ////////////// 多点触控 ///////////////////////////////////////////////////
    /*
    auto listener = EventListenerTouchAllAtOnce::create();
    
    listener->onTouchesBegan = [](std::vector<Touch*> touches,Event* e){
        Touch* t;
        for (auto it = touches.begin(); it != touches.end(); it++) {
            t = *it;
            CCLOG("%f ",t->getLocation().x);
        }
        
//        for (auto t:touches) {
//            CCLOG("%f ",t->getLocation().x);
//        }
        
    };
    listener->onTouchesMoved = [](std::vector<Touch*> touches,Event* e){
        
        CCLOG("%ld ",touches.size());
        
    };
    
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    */
    
    ////////////// 加速度传感器 ///////////////////////////////////////////////////
    /*
    //开启加速度传感器
    Device::setAccelerometerEnabled(true);
    
    auto listener = EventListenerAcceleration::create([](Acceleration* a, Event* e){
        CCLOG("x:%g,y:%g,z:%g \n",a->x,a->y,a->z);
    });
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
     */
    
    ////////////// 物理按键交互 ///////////////////////////////////////////////////
    /*
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = [](EventKeyboard::KeyCode code, Event* e){
        CCLOG("<<<");
        switch (code) {
            case cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE:
                Director::getInstance()->end();
                break;
                
            default:
                break;
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
     */
    
    ////////////// 计时器 ///////////////////////////////////////////////////
    /*
    auto scene = SchedulerUpData::createScene();
    addChild(scene);
     */
    
    ////////////// 用户首选项数据 ///////////////////////////////////////////////////
    /*
    UserDefault::getInstance()->setStringForKey("username", "123456");
    UserDefault::getInstance()->getStringForKey("username", "无用户名");
    */
    
    ////////////// 文件读写 ///////////////////////////////////////////////////
    /*
    auto fu = FileUtils::getInstance();
    
    //写
    CCLOG("可写入目录:%s ",fu->getWritablePath().c_str());
    FILE* file = fopen(fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath()).c_str(), "w");
    fprintf(file, "Hello");
    
    fclose(file);
     
    //读
    auto d = fu->getDataFromFile(fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath()));
    
    CCLOG("%s ",d.getBytes());
    */
    
    ////////////// xml ///////////////////////////////////////////////////
    /*
    addChild(XmlScene::createScene());
    */
     
    ////////////// 地图加载 ///////////////////////////////////////////////////
    /*
    auto map = TMXTiledMap::create("p01.tmx");
    addChild(map);
    
    //获取地图属性
    auto mapProperties = map->getProperties();
    auto str = mapProperties["type"].asString();
    CCLOG("%s ",str.c_str());
    
    //获取图层属性
    auto sceneLayer = map->getLayer("layer");
    auto layerProperties = sceneLayer->getProperties();
    CCLOG("%s ",layerProperties["type"].asString().c_str());
    
    //获取图块属性(图块从1开始)
    auto tilePro = map->getPropertiesForGID(1).asValueMap();
    CCLOG("%s ",tilePro["type"].asString().c_str());
    
    //获取对象属性
    auto objectGroup = map->getObjectGroup("object");
    auto obj = objectGroup->getObject("player");
    CCLOG("%s ",obj["type"].asString().c_str());
    
    
    //修改colorObj颜色
    auto colorObj = objectGroup->getObject("color");
    auto colorObjX = colorObj["x"].asInt()/32;
    auto colorObjY = colorObj["y"].asInt()/32;
    auto colorObjH = colorObj["height"].asInt()/32;
    auto colorObjW = colorObj["width"].asInt()/32;
    
    for (int x = colorObjX; x < colorObjX+colorObjW; x++) {
        for (int y = colorObjY; y < colorObjY+colorObjH; y++) {
            
            auto sprite = sceneLayer->getTileAt(Vec2(x, map->getMapSize().height - y));
            sprite->setColor(Color3B(255, 0, 0));
            
        }
    }
    
    //加载player
    auto player = Sprite::create("c.png");
//    player->setContentSize(Size(64, 64));
    player->setPosition(obj["x"].asFloat(),obj["y"].asFloat());
    addChild(player);
    
    
    //
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [map,sceneLayer,player](Touch* touch,Event* e){
        
        //触摸点转换成地图上的点
        auto point = map->convertToNodeSpace(touch->getLocation());
        point.x = static_cast<int>(point.x/32) + 1;
        point.y = map->getMapSize().height - (static_cast<int>(point.y/32)) - 1;
        
        //得到图层上的点
        auto t = sceneLayer->getTileAt(point);
        
//        t->setColor(Color3B(255, 0, 0));
        
        //获取触摸点模块的属性
        auto gid = sceneLayer->getTileGIDAt(point);
        //触摸点模块属性转换成ValueMap
        auto p = map->getPropertiesForGID(gid).asValueMap();
        
        if (p["move"].asString() == "true") {
            player->setPosition(t->getPosition());
        }
    
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    */
    
    ////////////// Cocos Studio ///////////////////////////////////////////////////
    
//    Director::getInstance()->runWithScene(CocosStudioScene::createScene());
    
    
    ////////////// 物理按键交互 ///////////////////////////////////////////////////
    
    return true;
}


