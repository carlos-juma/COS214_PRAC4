#ifndef __FloodedSoil__h__
#define __FloodedSoil__h__

#include "SoilState.h"
#include "Cropfield.h"

class FloodedSoil_ : public SoilState {
public:
    FloodedSoil_();
    void harvestCrops(Cropfield* cropField) override;
    void rain(Cropfield* cropField) override;
    std::string getName() const override;
};

#endif
