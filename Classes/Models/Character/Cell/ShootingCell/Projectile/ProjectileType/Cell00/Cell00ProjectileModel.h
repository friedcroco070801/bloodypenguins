#ifndef __CELL_00_PROJECTILE_MODEL_H__
#define __CELL_00_PROJECTILE_MODEL_H__

class ProjectileModel;
class CharacterModel;

class Cell00ProjectileModel : public ProjectileModel {
public:
    Cell00ProjectileModel(CharacterModel*, CharacterModel*);
    virtual ~Cell00ProjectileModel(){}
protected:
};

#endif // ! __CELL_00_PROJECTILE_MODEL_H__