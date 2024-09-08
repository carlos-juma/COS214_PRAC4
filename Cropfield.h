#include <exception>
#include <string>
using namespace std;

#ifndef __Cropfield_h__
#define __Cropfield_h__

// #include "SoilState.h"
#include "FarmUnit.h"

class SoilState;
// class FarmUnit;
class Cropfield;

class Cropfield: public FarmUnit
{
	protected: string _cropType;
	protected: int _totalCapacity;
	protected: int _currentStorage;
	protected: SoilState* _soilState;
	public: SoilState* _unnamed_SoilState_;

	public: void harvestCrops();

	public: void applyFertilizer();

	public: string getSoilStateName();

	public: string getCropType();

	public: int getTotalCapacity();
};

#endif
