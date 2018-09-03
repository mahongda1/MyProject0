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
    CREATE_FUNC(HelloWorld);//��Ϊһ���ض���������һ��create����
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

	CREATE_FUNC(SecondGround);//��Ϊһ���ض���������һ��create����
};


#endif // __HELLOWORLD_SCENE_H__
