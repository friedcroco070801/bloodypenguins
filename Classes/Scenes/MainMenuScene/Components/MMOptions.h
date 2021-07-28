#ifndef __MM_OPTIONS_H__
#define __MM_OPTIONS_H__

#include "cocos2d.h"


#define OPTIONS_LAYER_FORE_FILENAME "sprites/objects/button/layer_fore.png"
#define OPTIONS_LAYER_FILENAME "sprites/objects/button/layer.png"
#define OPTIONS_LAYER_OKAY_FILENAME "sprites/objects/button/layer_button_okay.png"
#define OPTIONS_LAYER_OKAY_CLICKED_FILENAME "sprites/objects/button/layer_button_okay_clicked.png"
#define OPTIONS_LAYER_MUSIC_FILENAME "sprites/objects/button/music.png"
#define OPTIONS_LAYER_EFFECT_FILENAME "sprites/objects/button/sound_effect.png"
#define OPTIONS_LAYER_SLIDER_FILENAME "sprites/objects/button/slider.png"
#define OPTIONS_LAYER_SLIDER_BASE_FILENAME "sprites/objects/button/slider_bar.png"
#define OPTIONS_TEXT_FILENAME "sprites/objects/button/options_text.png"


class MMOptions : public cocos2d::Layer {
public:
	static MMOptions* create();
	virtual bool init();
private:
    cocos2d::Sprite* music_slider;
    cocos2d::Sprite* effect_slider;

};

#endif // !__MM_OPTIONS_H__