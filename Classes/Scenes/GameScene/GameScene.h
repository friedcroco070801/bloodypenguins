#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include "Models/models.h"

class GameScene :public cocos2d::Scene 
{
public:
	CREATE_FUNC(GameScene);
	static Scene* createScene();
	virtual bool init();
	virtual ~GameScene() {delete level;}

protected:
	virtual void controlLayer();
	//virtual void backgroundLayer();
	virtual void informationLayer();
	LevelModel* level;
	void updateLevel(float);
};

#endif // !__GAMESCENE_H__