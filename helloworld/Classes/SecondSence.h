#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
class SecondSence :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SecondSence);//��Ϊһ���ض���������һ��create����
	cocos2d::SEL_SCHEDULE selector;	
	virtual void update(float dt);
	cocos2d::ProgressTimer *layer;//������ָ��
};

