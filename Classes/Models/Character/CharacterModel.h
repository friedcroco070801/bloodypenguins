#ifndef __CHARACTER_MODEL_H__
#define __CHARACTER_MODEL_H__

#include "CharacterModelDefinitions.h"

struct CellPosition {
    float cellX, cellY;
    CellPosition(float x, float y) {cellX = x; cellY = y;}
};

class CharacterModel {
protected:
    CharacterType type;
    int hp;
    CharacterStatus status;
    bool alive;
    float cellX;
    float cellY;
public:
    CharacterModel(){};
    CharacterModel(CharacterType);
    virtual void takeDamage(int);
    virtual void setStatus(CharacterStatus);
    virtual bool isAlive();
    virtual void setPosition(float, float);
    virtual CellPosition getPosition();
    virtual float getPositionCellX();
    virtual float getPositionCellY();
    virtual void update();
    virtual ~CharacterModel();
};

#endif // !__CHARACTER_MODEL_H__