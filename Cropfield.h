#ifndef __Cropfield_h__
#define __Cropfield_h__

#include "FarmUnit.h"
#include "SoilState.h"

class Cropfield : public FarmUnit {
protected:
    std::string cropType;
    int totalCapacity;
    int currentStorage;
    SoilState* soilState;

public:
    Cropfield(std::string cropType, int totalCapacity, SoilState* soilState);

    void harvestCrops() override;
    void applyFertilizer();
    std::string getSoilStateName();
    std::string getCropType();
    int getTotalCapacity();
    void storeCrops(int amount);
    void increaseProduction();
    int getLeftoverCapacity();
    SoilState* getSoilState();  // Add this getter
};

#endif
