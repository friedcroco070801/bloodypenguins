#include "Models/models.h"
#include "Disease02Model.h"

Disease02Model::Disease02Model() : DiseaseModel(DISEASE_02_INFLUENZA) {
    // Temporary data
    speed = 1;
    damage = 2;
    hitRechargeTime = 0.5;
    hp = 7;
}