#ifndef __Truck_h__
#define __Truck_h__
#include <iostream>  

#include <string>
#include "FarmUnit.h"

class FarmUnit;

class Truck {
private:
    std::string name;

public:
    Truck(std::string name) : name(name) {}
    virtual void update(FarmUnit* aUnit) = 0;  // Pure virtual function for observer
    void startEngine();
    std::string getName() const { return name; }
};

#endif
