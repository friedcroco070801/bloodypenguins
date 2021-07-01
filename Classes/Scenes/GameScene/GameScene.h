#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"


class GameScene :public cocos2d::Scene 
{
public:
	CREATE_FUNC(GameScene);
	static Scene* createScene();
	virtual bool init();

protected:
	virtual void controlLayer();
	//virtual void backgroundLayer();
	virtual void informationLayer();
};

#endif // !__GAMESCENE_H__