#include <exception>
using namespace std;

#ifndef __ExtraBarn_h__
#define __ExtraBarn_h__

#include "Barn.h"

// class Barn;
class ExtraBarn;

class ExtraBarn: public Barn
{

	public: void increaseProduction();

	public: void harvestCrops();

	public: int getLeftoverCapacity();

	public: int getTotalCapacity();
};

#endif
