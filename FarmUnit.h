#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __FarmUnit_h__
#define __FarmUnit_h__

// #include "Truck.h"
// #include "Farmland.h"
// #include "Client.h"

class Truck;
// class Farmland;
class Client;
class FarmUnit;

class FarmUnit
{
	public: string _farmName;
	protected: vector<Truck*> _trucks;
	public: Farmland* _unnamed_Farmland_;
	public: Client* _unnamed_Client_;
	public: Truck* _unnamed_Truck_;

	public: int getTotalCapacity();

	public: string getCropType();

	public: string getSoilStateName();

	public: FarmUnit* getChild(string aInt_26);

	public: void add(string aFarmUnit);

	public: void remove(string aFarmunit);

	public: void attachTruck(Truck* aTruck);

	public: void detachTruck(Truck* aTruck);

	public: void notifyTrucks();

	public: void triggerFertilization();

	public: void triggerCropCollection();
};

#endif
