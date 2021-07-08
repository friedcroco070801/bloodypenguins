#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include "Models/models.h"
#include "GSMap.h"
class GameScene :public cocos2d::Scene 
{
public:
	CREATE_FUNC(GameScene);
	static Scene* createScene();
	virtual bool init();
	virtual ~GameScene() {delete level;}

	void addEnergyLabel(int);
	
protected:
	virtual void controlLayer(LevelModel* level);
	virtual void drawMap();

	virtual void addBackground();

	LevelModel* level;
	void updateLevel(float);
};

#endif // !__GAMESCENE_H__