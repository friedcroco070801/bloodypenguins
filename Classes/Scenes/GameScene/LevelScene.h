#ifndef __LEVELSCENE_H__
#define __LEVELSCENE_H__
#include "cocos2d.h"
#include "Models/models.h"

#define NUMBER_LEVEL 8
USING_NS_CC;
class levelScene :public cocos2d::Scene
{
public:
	CREATE_FUNC(levelScene);
	static Scene* createScene();
	virtual bool init();
	virtual ~levelScene() {};

protected:
	virtual void LoopCreate();
	virtual void CreateButtonLevel(int level);
};
#endif // !__LEVELSCENE_H__