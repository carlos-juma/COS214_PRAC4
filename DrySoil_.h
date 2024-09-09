#ifndef __DrySoil__h__
#define __DrySoil__h__

#include "SoilState.h"
#include <string>

class DrySoil_ : public SoilState {
public:
    DrySoil_();
    void harvestCrops(Cropfield* cropField) override;
    void rain(Cropfield* cropField) override;
    std::string getName() const override;
};

#endif
