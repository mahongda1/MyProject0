#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
class SecondSence :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SecondSence);//来为一个特定的类增加一个create函数
	cocos2d::SEL_SCHEDULE selector;	
	virtual void update(float dt);
	cocos2d::ProgressTimer *layer;//进度条指针
};

