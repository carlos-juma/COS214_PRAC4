#ifndef __DeliveryTruck_h__
#define __DeliveryTruck_h__

#include "Truck.h"
#include "FarmUnit.h"

class DeliveryTruck : public Truck {
public:
    DeliveryTruck(std::string name) : Truck(name) {}
    void update(FarmUnit* unit) override;
};

#endif
