#include <exception>
#include <string>
using namespace std;

#ifndef __FertilizeField_h__
#define __FertilizeField_h__

#include "Cropfield.h"

// class Cropfield;
class FertilizeField;

class FertilizeField: public Cropfield
{

	public: void increaseProduction();

	public: void harvestCrops();

	public: string getSoilStateName();
};

#endif
