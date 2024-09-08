#include <exception>
#include <stack>
using namespace std;

#ifndef __DepthFirstIterator_h__
#define __DepthFirstIterator_h__

// #include "FarmUnit.h"
#include "FarmIterator.h"

class FarmUnit;
// class FarmIterator;
class DepthFirstIterator;

class DepthFirstIterator: public FarmIterator
{
	private: stack<FarmUnit*> _stack;

	public: FarmUnit* firstFarm();

	public: FarmUnit* nextFarm();

	public: bool isDone();

	public: FarmUnit* currentFarm();
};

#endif
