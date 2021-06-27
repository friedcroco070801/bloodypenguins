#ifndef __CHARACTER_MODEL_H__
#define __CHARACTER_MODEL_H__

#include "CharacterModelDefinitions.h"

class CharacterModel {
protected:
    int hp;
    CharacterStatus status;
public:
    CharacterModel();
    virtual ~CharacterModel();
};

#endif // !__CHARACTER_MODEL_H__