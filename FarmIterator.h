#include <exception>
using namespace std;

#ifndef __FarmIterator_h__
#define __FarmIterator_h__

// #include "Client.h"
// #include "FarmUnit.h"

class Client;
class FarmUnit;
class FarmIterator;

class FarmIterator
{
	public: Client* _unnamed_Client_;

	public: FarmUnit* firstFarm();

	public: FarmUnit* nextFarm();

	public: bool isDone();

	public: FarmUnit* currentFarm();
};

#endif
