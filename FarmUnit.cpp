#include "FarmUnit.h"
#include "Truck.h"
#include <iostream>
#include "FruitfulSoil_.h"  // Include the correct header for FruitfulSoil_

using namespace std;

FarmUnit::FarmUnit(string name, int totalCapacity, string cropType, SoilState* soilState)
    : name(name), totalCapacity(totalCapacity), currentStorage(0), soilState(soilState) {}

string FarmUnit::getName() const {
    return name;
}

int FarmUnit::getTotalCapacity() const {
    return totalCapacity;
}

int FarmUnit::getCurrentStorage() const {
    return currentStorage;
}

string FarmUnit::getSoilStateName() const {
    return soilState->getName();
}

void FarmUnit::harvestCrops() {
    cout << "Harvesting crops at " << name << endl;
    notifyTrucks();  // Notify trucks after harvesting
}

void FarmUnit::triggerCropCollection() {
    cout << "Triggering crop collection at " << name << endl;
    currentStorage = 0;  // Reset the current storage
    notifyTrucks();  // Notify trucks about the collection
}

void FarmUnit::triggerFertilization() {
    cout << "Fertilization triggered at " << name << endl;

    // Ensure the soil state changes to "Fruitful" after fertilization
    if (soilState->getName() == "Dry") {
        soilState = new FruitfulSoil_();  // Transition to fruitful soil after fertilization
        cout << "Soil state has changed to Fruitful." << endl;
    }
}

// Observer pattern methods
void FarmUnit::attachTruck(Truck* truck) {
    trucks.push_back(truck);
}

#include "FarmUnit.h"
#include <algorithm>  // Include algorithm for std::remove

void FarmUnit::detachTruck(Truck* truck) {
    auto it = std::remove(trucks.begin(), trucks.end(), truck);  // Correct use of std::remove
    trucks.erase(it, trucks.end());  // Erase the truck from the vector
}

void FarmUnit::notifyTrucks() {
    for (Truck* truck : trucks) {
        truck->update(this);
    }
}

// Methods for child farm units
int FarmUnit::getChildrenCount() const {
    return children.size();
}

FarmUnit* FarmUnit::getChild(int index) {
    if (index >= 0 && index < children.size()) {
        return children[index];
    }
    return nullptr;
}

void FarmUnit::addChild(FarmUnit* child) {
    children.push_back(child);
}
