#ifndef __ExtraGreenHouse_h__
#define __ExtraGreenHouse_h__

#include "GreenHouse.h"

class ExtraGreenHouse : public GreenHouse {
public:
    // Constructor for ExtraGreenHouse
    ExtraGreenHouse(std::string name, int totalCapacity, std::string cropType, SoilState* soilState, bool controlledEnvironment)
        : GreenHouse(name, totalCapacity, cropType, soilState, controlledEnvironment) {}

    void increaseProduction();
    void harvestCrops();
    int getLeftoverCapacity();
    int getTotalCapacity();
};

#endif
