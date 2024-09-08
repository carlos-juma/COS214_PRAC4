#include <exception>
#include <string>
using namespace std;

#ifndef __DrySoil__h__
#define __DrySoil__h__

#include "SoilState.h"

// class SoilState;
class DrySoil_;

class DrySoil_: public SoilState
{

	public: void harvestCrops(string aCropField);

	public: void rain(string aCropField);

	public: string getName();
};

#endif
