#ifndef __FertilizerTruck_h__
#define __FertilizerTruck_h__

#include "Truck.h"
#include "FarmUnit.h"

class FertilizerTruck : public Truck {
public:
    FertilizerTruck(std::string name) : Truck(name) {}
    void update(FarmUnit* aUnit) override;
};

#endif
