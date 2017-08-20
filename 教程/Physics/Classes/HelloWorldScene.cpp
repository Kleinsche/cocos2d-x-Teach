#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;



using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    //显示所有调试信息
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    //重力加速度
    scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
    
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    

    
    return true;
}

void HelloWorld::onEnter(){
    Layer::onEnter();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* t,Event* e){
        
        addBall(t->getLocation());
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto contentListener = EventListenerPhysicsContact::create();
    contentListener->onContactBegin = [this](PhysicsContact& contact){
        
        switch (contact.getShapeA()->getBody()->getContactTestBitmask() | contact.getShapeB()->getBody()->getContactTestBitmask()) {
            case 0b1000 | 0b0100:
                CCLOG("红与边界");
                contact.getShapeB()->getBody()->getNode()->removeFromParent();
                break;
                
            case 0b1000 | 0b0010:
                CCLOG("绿与边界");
                contact.getShapeB()->getBody()->getNode()->removeFromParent();
                break;
                
            case 0b1000 | 0b0001:
                CCLOG("蓝与边界");
                contact.getShapeB()->getBody()->getNode()->removeFromParent();
                break;
                
            case 0b0100 :
                CCLOG("红与红");
                break;
                
            case 0b0100 | 0b0010:
                CCLOG("红与绿");
                break;
                
            case 0b0100 | 0b0001:
                CCLOG("红与蓝");
                break;
                
            case 0b0010:
                CCLOG("绿与绿");
                break;
                
            case 0b0010 | 0b0001:
                CCLOG("绿与蓝");
                break;
                
            case 0b0001:
                CCLOG("蓝与蓝");
                break;
                
            default:
                break;
        }
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority( contentListener, this);
    
    addEdges();
    
}

//界面边框
void HelloWorld::addEdges(){
    auto body = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3);
    
    auto edgeShape = Node::create();
    edgeShape->setPhysicsBody(body);
    edgeShape->setPosition(visibleSize/2);
    addChild(edgeShape);
    edgeShape->getPhysicsBody()->setContactTestBitmask(EDGE_BIT_MASK);
    
}

void HelloWorld::addBall(Vec2 vec){
    
    auto b = Sprite::create();
    b->setTextureRect(Rect(0, 0, 30, 30));
    b->setPhysicsBody(PhysicsBody::createBox(b->getContentSize()));
    b->setPosition(vec);
//    b->setColor(Color3B(random(0, 255), random(0, 255), random(0, 255)));
    addChild(b);
    
    switch (rand()%3) {
        case 0:
            b->setColor(Color3B(255, 0, 0));
            b->getPhysicsBody()->setContactTestBitmask(RED_BIT_MASK);
            //发射
            b->getPhysicsBody()->setVelocity(Vec2(0, 500));
            break;
            
        case 1:
            b->setColor(Color3B(0, 255, 0));
            b->getPhysicsBody()->setContactTestBitmask(GREEN_BIT_MASK);
            b->getPhysicsBody()->setVelocity(Vec2(0, 500));
            break;
            
        case 2:
            b->setColor(Color3B(0, 0, 255));
            b->getPhysicsBody()->setContactTestBitmask(BLUE_BIT_MASK);
            b->getPhysicsBody()->setVelocity(Vec2(0, 500));
            break;
            
        default:
            break;
    }
    

}




