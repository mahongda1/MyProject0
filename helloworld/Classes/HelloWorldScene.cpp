#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "SecondSence.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	

    // return the scene
    return scene;
}
bool SecondGround::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::create("menu/321.jpg");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScale(0.75f);
	bg->getContentSize().width;
	log("%f,%f", bg->getContentSize().width, bg->getContentSize().height);
	this->addChild(bg);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("menu/12111.mp3", true); //播放背景音乐
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/Jazz.mp3");  //停止播放
	auto logoMenuItem = MenuItemImage::create("menu/1434.png", "menu/1434.png");
	auto listMenuItem = MenuItemImage::create("menu/TransferRoll_box.png", "menu/TransferRoll_box.png");
	listMenuItem->setPosition(Vec2(1200, 450));
	auto xianluMenuItem = MenuItemImage::create("menu/f2.png", "menu/f1.png",CC_CALLBACK_1(HelloWorld::menuCallback, this));
	auto fuwuqiMenuItem = MenuItemImage::create("menu/b2.png", "menu/b1.png",  CC_CALLBACK_1(HelloWorld::gomenuCallback, this));
	auto jinruMenuItem = MenuItemImage::create("menu/c2.png", "menu/c1.png", CC_CALLBACK_1(HelloWorld::inmenuCallback, this));
	auto tuichuMenuItem = MenuItemImage::create("menu/d2.png", "menu/d1.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	logoMenuItem->setPosition(Vec2(1100, 110));
	logoMenuItem->setScale(0.4f);
	xianluMenuItem->setPosition(Vec2(1200, 533));
	//xianluMenuItem->setScale(2.0f);
	fuwuqiMenuItem->setPosition(Vec2(1200, 493));
	//fuwuqiMenuItem->setScale(2.0f);
	jinruMenuItem->setPosition(Vec2(1200, 453));
	//jinruMenuItem->setScale(2.0f);
	tuichuMenuItem->setPosition(Vec2(1200, 413));
	//tuichuMenuItem->setScale(2.0f);
	auto mn1= Menu::create(logoMenuItem, NULL);
	mn = Menu::create(listMenuItem,xianluMenuItem, fuwuqiMenuItem, jinruMenuItem, tuichuMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	mn1->setPosition(Vec2::ZERO);
	this->addChild(mn);
	this->addChild(mn1);
	auto sha = Sprite::create("menu/01.png");//创建一个sprite让它跑起来
	sha->setPosition(Vec2(90, 560));
	this->addChild(sha, 0);
	auto*animation = Animation::create();
	for (int i = 1; i < 9; i++)
	{
		char s[20] = { 0 };
		sprintf(s, "menu/0%d.png", i);
		animation->addSpriteFrameWithFile(s);
	}
	animation->setLoops(-1);//循环多少词，-1是无限次循环
	animation->setDelayPerUnit(0.1f);//每隔多久切换一次动画，0.1秒
	auto* action = Animate::create(animation);
	sha->runAction(action);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("menu/1123.wav");

	
    return true;
}
void HelloWorld::update(float dt) 
{	
	

}



 
void HelloWorld::menuCloseCallback(Ref* pSender)

{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("menu/1123.wav");
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::menuCallback(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("menu/1123.wav");
	
}
void HelloWorld::gomenuCallback(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("menu/1123.wav");
	this->mn->setVisible(false);
	auto layer1 = SecondGround::create();
	auto listMenuItem = MenuItemImage::create("menu/1121.png", "menu/1121.png");
	auto fanhuiMenuItem = MenuItemImage::create("menu/cancel_2.png", "menu/cancel_1.png",CC_CALLBACK_1(HelloWorld::retrunmenuCallback, this));
	auto quedingMenuItem = MenuItemImage::create("menu/achieve_2.png", "menu/achieve_1.png", CC_CALLBACK_1(HelloWorld::retrunmenuCallback, this));
	listMenuItem->setPosition(Vec2(1200, 450));
	fanhuiMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(1250,630)));
	quedingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(1150, 630)));
	mn2 = Menu::create(listMenuItem, fanhuiMenuItem, quedingMenuItem, NULL);
	mn2->setPosition(Vec2::ZERO);
	this->addChild(mn2);
}
void HelloWorld::retrunmenuCallback(cocos2d::Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("menu/1123.wav");
	this->mn2->setVisible(false);
	this->mn->setVisible(true);
}
void HelloWorld::inmenuCallback(cocos2d::Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("menu/1123.wav");
	auto scene2 = SecondSence::createScene();
	Director::getInstance()->replaceScene(scene2);
	
}