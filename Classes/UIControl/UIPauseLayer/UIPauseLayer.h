#ifndef __UI_PAUSE_LAYER_H__
#define __UI_PAUSE_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define PAUSE_LAYER_FORE_FILENAME "sprites/objects/button/layer_fore.png"
#define PAUSE_LAYER_FILENAME "sprites/objects/button/layer.png"
#define PAUSE_LAYER_RESUME_FILENAME "sprites/objects/button/layer_button_resume.png"
#define PAUSE_LAYER_RESUME_CLICKED_FILENAME "sprites/objects/button/layer_button_resume_clicked.png"

class LevelModel;

class UIPauseLayer : public cocos2d::Layer {
public:
    static UIPauseLayer* create(LevelModel*);
    void init(LevelModel*);
private:
    LevelModel* level;
};

#endif // !__UI_PAUSE_LAYER_H__