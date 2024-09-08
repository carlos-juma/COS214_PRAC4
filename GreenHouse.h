#include <exception>
#include <string>
using namespace std;

#ifndef __GreenHouse_h__
#define __GreenHouse_h__

#include "FarmUnit.h"

// class FarmUnit;
class GreenHouse;

class GreenHouse: public FarmUnit
{
	protected: string _cropType;
	protected: int _totalCapacity;
	protected: int _currentStored;
	protected: bool _controlledEnvironment;

	public: int getTotalCapacity();

	public: string getCropType();

	public: string getEnvironmentState();

	public: int getCurrentStored();

	public: void setCurrentStored(int aAmount);

	public: void operation();
};

#endif
