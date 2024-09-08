#include <exception>
#include <string>
using namespace std;

#ifndef __SoilState_h__
#define __SoilState_h__

// #include "Cropfield.h"

class Cropfield;
class SoilState;

class SoilState
{
	protected: string _name;
	public: Cropfield* _unnamed_Cropfield_;

	public: void harvestCrops(string aCropField);

	public: void rain(string aCropField);

	public: string getName();
};

#endif
