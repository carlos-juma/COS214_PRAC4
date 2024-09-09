#ifndef __FruitfulSoil__h__
#define __FruitfulSoil__h__

#include "SoilState.h"
#include <string>

class FruitfulSoil_ : public SoilState {
public:
    FruitfulSoil_();
    void harvestCrops(Cropfield* aCropField) override;
    void rain(Cropfield* aCropField) override;
    std::string getName() const override;
};

#endif
