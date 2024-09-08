#include <exception>
#include <string>
using namespace std;

#ifndef __FruitfulSoil__h__
#define __FruitfulSoil__h__

#include "SoilState.h"

// class SoilState;
class FruitfulSoil_;

class FruitfulSoil_: public SoilState
{

	public: void harvestCrops(string aCropField);

	public: void rain(string aCropField);

	public: string getName();
};

#endif
