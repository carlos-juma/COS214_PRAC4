#ifndef __ExtraBarn_h__
#define __ExtraBarn_h__

#include "Barn.h"

class ExtraBarn : public Barn {
public:
    ExtraBarn(std::string barnName, int capacity, SoilState* soilState);  // Constructor

    void increaseProduction();
    void harvestCrops();
    int getLeftoverCapacity();
    int getTotalCapacity();
};

#endif
