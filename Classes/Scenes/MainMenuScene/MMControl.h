#ifndef __MM_CONTROL_H__
#define __MM_CONTROL_H__

#include "cocos2d.h"
#include "Models/models.h"
#include "Scenes/GameScene/GSDefine.h"
#include <functional>
#include "Scenes/GameScene/GameScene.h"

#define PLAY_LAYER_FILENAME "sprites/objects/button/play_layer_button_mainmenu.png"
#define PLAY_LAYER_CLICKED_FILENAME "sprites/objects/button/play_layer_button_mainmenu_clicked.png"
#define OPTIONS_LAYER_FILENAME "sprites/objects/button/options_layer_button_mainmenu.png"
#define OPTIONS_LAYER_CLICKED_FILENAME "sprites/objects/button/options_layer_button_mainmenu_clicked.png"
#define QUIT_LAYER_FILENAME "sprites/objects/button/quit_layer_button_mainmenu.png"
#define QUIT_LAYER_CLICKED_FILENAME "sprites/objects/button/quit_layer_button_mainmenu_clicked.png"


using namespace cocos2d;

class GameScene;

class MMControl : public cocos2d::Scene
{
public:
	CREATE_FUNC(MMControl);
	virtual bool init();

private:

	//void GoToLevelScene(cocos2d::Ref *sender);
	void GoToGameScene(cocos2d::Ref *sender);
	void GoToOptionsCom(cocos2d::Ref *sender);
	void ExitGameMain(cocos2d::Ref *sender);
	void addButtonMenu();


};

#endif // !__MM_CONTROL_H__