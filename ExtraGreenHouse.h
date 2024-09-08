#include <exception>
using namespace std;

#ifndef __ExtraGreenHouse_h__
#define __ExtraGreenHouse_h__

#include "GreenHouse.h"

// class GreenHouse;
class ExtraGreenHouse;

class ExtraGreenHouse: public GreenHouse
{

	public: void increaseProduction();

	public: void harvestCrops();

	public: int getLeftoverCapacity();

	public: int getTotalCapacity();
};

#endif
