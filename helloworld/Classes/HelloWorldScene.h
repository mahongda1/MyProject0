#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	cocos2d::Menu *mn;
	cocos2d::Menu *mn2;
    virtual bool init();
	// a selector callback
    void HelloWorld::menuCloseCallback(cocos2d::Ref* pSender);
	void HelloWorld::menuCallback(Ref* pSender);
	void HelloWorld::gomenuCallback(cocos2d::Ref* pSender);
	void HelloWorld::inmenuCallback(cocos2d::Ref* pSender);
	void HelloWorld::retrunmenuCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);//来为一个特定的类增加一个create函数
	virtual void update(float dt);
	//cocos2d::Label* label;
	cocos2d::SEL_SCHEDULE selector;
	//int state=0;
};
class SecondGround :
	public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(SecondGround);//来为一个特定的类增加一个create函数
};


#endif // __HELLOWORLD_SCENE_H__
