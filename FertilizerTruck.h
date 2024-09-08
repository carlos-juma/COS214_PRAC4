#include <exception>
using namespace std;

#ifndef __FertilizerTruck_h__
#define __FertilizerTruck_h__

// #include "FarmUnit.h"
#include "Truck.h"

class FarmUnit;
// class Truck;
class FertilizerTruck;

class FertilizerTruck: public Truck
{

	public: void update(FarmUnit* aUnit);
};

#endif
