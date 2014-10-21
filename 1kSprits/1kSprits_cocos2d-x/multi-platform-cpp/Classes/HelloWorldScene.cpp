#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();


    int max = 1000;
    int width = size.width;
    int height = size.height;

    for (int i =0; i<max; i++) {
        CCSprite* sprite = CCSprite::create("HelloWorld.png");
        sprite->setPosition(CCPoint(width/2, height/2));
        CCMoveBy* action;
        float arch = 2*3.1415/max * i;
        float x = width/2 * sin(arch);
        float y = width/2 * cos(arch);
        action = CCMoveBy::create(3, CCPoint(x, y));
            
        CCDelayTime* delay = CCDelayTime::create(0.25);
        CCAction* reverse = action->reverse();
        CCSequence* sequence = CCSequence::create(action, delay, reverse, 0);
        CCRepeatForever* repeat = CCRepeatForever::create(sequence);
        this->addChild(sprite);
        sprite->runAction(repeat);
        CCRepeatForever* rotateForever = CCRepeatForever::create(CCRotateBy::create(3, 360));
        sprite->runAction(rotateForever);
    }

    return true;
}
 
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
