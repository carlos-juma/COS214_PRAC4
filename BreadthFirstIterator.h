#include <exception>
#include <queue>
using namespace std;

#ifndef __BreadthFirstIterator_h__
#define __BreadthFirstIterator_h__

// #include "FarmUnit.h"
#include "FarmIterator.h"

class FarmUnit;
// class FarmIterator;
class BreadthFirstIterator;

class BreadthFirstIterator: public FarmIterator
{
	private: queue<FarmUnit*> _queue;

	public: FarmUnit* firstFarm();

	public: FarmUnit* nextFarm();

	public: bool isDone();

	public: FarmUnit* currentFarm();
};

#endif
