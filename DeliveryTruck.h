#include <exception>
using namespace std;

#ifndef __DeliveryTruck_h__
#define __DeliveryTruck_h__

// #include "FarmUnit.h"
#include "Truck.h"

class FarmUnit;
// class Truck;
class DeliveryTruck;

class DeliveryTruck: public Truck
{

	public: void update(FarmUnit* aUnit);
};

#endif
