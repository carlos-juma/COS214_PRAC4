#include <exception>
#include <string>
using namespace std;

#ifndef __FloodedSoil__h__
#define __FloodedSoil__h__

#include "SoilState.h"

// class SoilState;
class FloodedSoil_;

class FloodedSoil_: public SoilState
{

	public: void harvestCrops(string aCropField);

	public: void rain(string aCropField);

	public: string getName();
};

#endif
