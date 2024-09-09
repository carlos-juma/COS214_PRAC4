#ifndef __Barn_h__
#define __Barn_h__

#include "FarmUnit.h"

class Barn : public FarmUnit {
public:
    Barn(std::string barnName, int capacity, SoilState* soilState);  // Constructor

    void storeCrops(int aAmount);
    void retrieveCrops(int aAmount);
    int getAvailableCapacity();
    std::string getBarnName();
    int getCurrentStorage();

protected:
    std::string _barnName;
    int _capacity;
    int _currentStorage;
};

#endif
