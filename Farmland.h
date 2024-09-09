#ifndef __Farmland_h__
#define __Farmland_h__

#include "FarmUnit.h"
#include <vector>
#include <algorithm>

class Farmland : public FarmUnit {
protected:
    std::vector<FarmUnit*> _units;  // Vector to store child farm units

public:
    // Constructor to initialize Farmland with the required base class arguments
    Farmland(std::string name, int totalCapacity, std::string cropType, SoilState* soilState)
        : FarmUnit(name, totalCapacity, cropType, soilState) {}

    void addUnit(FarmUnit* unit);      // Method to add a FarmUnit
    void removeUnit(FarmUnit* unit);   // Method to remove a FarmUnit
    int getTotalCapacity();            // Get total capacity of all units
    FarmUnit* getUnit(int index);      // Get a specific unit by index
    void notifyAllUnits(std::string operation);  // Notify all units about an operation (e.g., harvest, fertilize)
};

#endif
