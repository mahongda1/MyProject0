#include "SecondSence.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* SecondSence::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = SecondSence::create();
	// add layer as a child to scene
	scene->addChild(layer);


	// return the scene
	return scene;
}
bool SecondSence::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg = Sprite::create("menu/bg4.jpg");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->getContentSize().width;
	log("%f,%f", bg->getContentSize().width, bg->getContentSize().height);
	this->addChild(bg);
	auto loadingmenu = Sprite::create("menu/LoadingBar_BG.png");
	this->addChild(loadingmenu,0);
	loadingmenu->setPosition(Vec2(720,70));
	auto loadingmenu1 = Sprite::create("menu/loading_3.png");
	ProgressTimer* progress = CCProgressTimer::create(loadingmenu1);
	progress->setPosition(Vec2(426, 67));
	progress->setAnchorPoint(Point(0, 0));
	this->addChild(progress, 0);
	progress->setType(kCCProgressTimerTypeBar);
	progress->setBarChangeRate(ccp(1, 0));
	progress->setMidpoint(ccp(0, 0));
	progress->setTag(100);
	this->scheduleUpdate();
	return true;
}
void SecondSence::update(float dt)
{
	ProgressTimer* progress = (CCProgressTimer*)getChildByTag(100);

	//设置progress的进度，每调用一次进度加一
	progress->setPercentage(progress->getPercentage() + 0.3);

	//当进度大于或者等于100时
	if (progress->getPercentage() >= 100)
	{
		//终止定时器
		unscheduleAllSelectors();
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}


}