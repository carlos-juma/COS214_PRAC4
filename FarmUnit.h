#ifndef __FarmUnit_h__
#define __FarmUnit_h__

#include <string>
#include <vector>
#include "SoilState.h"
#include "Truck.h"

class Truck;

class FarmUnit {
protected:
    std::string name;
    int totalCapacity;
    int currentStorage;
    SoilState* soilState;
    std::vector<FarmUnit*> children;  // Vector to store child farm units
    std::vector<Truck*> trucks;       // Vector to store observer trucks

public:
    FarmUnit(std::string name, int totalCapacity, std::string cropType, SoilState* soilState);

    std::string getName() const;
    int getTotalCapacity() const;
    int getCurrentStorage() const;
    std::string getSoilStateName() const;

    virtual void harvestCrops();

    // Observer methods
    void attachTruck(Truck* truck);    // Attach a truck (observer)
    void detachTruck(Truck* truck);    // Detach a truck (observer)
    void notifyTrucks();               // Notify all attached trucks (observers)

    // Methods for managing child farm units
    int getChildrenCount() const;  // Returns the number of children
    FarmUnit* getChild(int index); // Returns the child at the specified index
    void addChild(FarmUnit* child); // Add a child farm unit to the list

    // Triggers
    void triggerCropCollection();  // Trigger crop collection (used by trucks)
    void triggerFertilization();   // Trigger fertilization (used by trucks)
};

#endif
