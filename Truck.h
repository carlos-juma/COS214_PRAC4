#include <exception>
#include <string>
using namespace std;

#ifndef __Truck_h__
#define __Truck_h__

// #include "FarmUnit.h"

class FarmUnit;
class Truck;

class Truck
{
	private: string _name;
	public: FarmUnit* _unnamed_FarmUnit_;

	public: void update(FarmUnit* aUnit);

	public: void startEngine();
};

#endif
