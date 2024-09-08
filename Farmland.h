#include <vector>
using namespace std;

#ifndef __Farmland_h__
#define __Farmland_h__

#include "FarmUnit.h"

// class FarmUnit;
class Farmland;

class Farmland: public FarmUnit
{
	protected: vector<FarmUnit*> _units;
	public: FarmUnit* _unnamed_FarmUnit_;
};

#endif
