#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
//    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
//    scene->addChild(layer);

    // return the scene
    CCTexture2D* testure = CCTextureCache::sharedTextureCache()->addImage("HelloWorld.png");

    CCParticleSystemQuad* particleSystem = CCParticleSystemQuad::createWithTotalParticles(3000);
    particleSystem->setTexture(testure);
    cocos2d::CCSize s = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    // duration
    particleSystem->setDuration(-1);

    // gravity
    cocos2d::CCPoint v(0, -90);
    particleSystem->setGravity(v);

    // angle
    particleSystem->setAngle(90);
    particleSystem->setAngleVar(0);

    // radial
    particleSystem->setRadialAccel(0);
    particleSystem->setRadialAccelVar(0);

    // speed of particles
    particleSystem->setSpeed(180);
    particleSystem->setSpeedVar(50);

    // emitter position
    particleSystem->setPosition(s.width / 2, 100);
    cocos2d::CCPoint v2(s.width / 2, 0);
    particleSystem->setPosVar(v2);

    // life of particles
    particleSystem->setLife(2.0);
    particleSystem->setLifeVar(1);

    // emits per frame
    particleSystem->setEmissionRate(particleSystem->getTotalParticles() / particleSystem->getLife());
    
    // color of particles
    cocos2d::ccColor4F startColor = {0.5, 0.5, 0.5, 1.0};
    particleSystem->setStartColor(startColor);

    cocos2d::ccColor4F startColorVar = {0.5, 0.5, 0.5, 1.0};
    particleSystem->setStartColorVar(startColorVar);
    
    cocos2d::ccColor4F endColor = {0.1, 0.1, 0.1, 0.2};
    particleSystem->setEndColor(endColor);

    cocos2d::ccColor4F endColorVar = {0.1, 0.1, 0.1, 0.2};
    particleSystem->setEndColorVar(endColorVar);
    
    // size, in pixels
    particleSystem->setEndSize(32.0);
    particleSystem->setStartSize(32.0);
    particleSystem->setEndSizeVar(0);
    particleSystem->setStartSizeVar(0);

    // additive
    particleSystem->setBlendAdditive(false);

    scene->addChild(particleSystem);

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
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
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
