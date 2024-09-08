#include <exception>
#include <string>
using namespace std;

#ifndef __Barn_h__
#define __Barn_h__

#include "FarmUnit.h"

// class FarmUnit;
class Barn;

class Barn: public FarmUnit
{
	protected: string _barnName;
	protected: int _capacity;
	protected: int _currentStorage;

	public: void storeCrops(int aAmount);

	public: void retrieveCrops(int aAmount);

	public: int getAvailableCapacity();

	public: string getBarnName();

	public: int getCurrentStorage();
};

#endif
