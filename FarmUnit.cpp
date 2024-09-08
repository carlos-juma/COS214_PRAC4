#include "FarmUnit.h"
#include "Truck.h"
#include "Farmland.h"
#include "Client.h"
#include "SoilState.h"
#include <iostream>
#include <algorithm>

// Constructor for FarmUnit
FarmUnit::FarmUnit(string name, int totalCapacity, string cropType, SoilState* soilState) 
    : _farmName(name), totalCapacity(totalCapacity), cropType(cropType), soilState(soilState) {}

// Returns the total capacity of the farm unit
int FarmUnit::getTotalCapacity() {
    return totalCapacity;
}

// Returns the type of crop
string FarmUnit::getCropType() {
    return cropType;
}

// Returns the name of the current soil state
string FarmUnit::getSoilStateName() {
    return soilState->getName();
}

// Add a child FarmUnit
void FarmUnit::add(FarmUnit* aFarmUnit) {
    _childUnits.push_back(aFarmUnit);
}

// Remove a child FarmUnit
void FarmUnit::remove(FarmUnit* aFarmUnit) {
    _childUnits.erase(std::remove(_childUnits.begin(), _childUnits.end(), aFarmUnit), _childUnits.end());
}

// Return a child farm unit by index
FarmUnit* FarmUnit::getChild(int index) {
    if (index < _childUnits.size()) {
        return _childUnits[index];
    }
    return nullptr;
}

// Attach a truck to the farm
void FarmUnit::attachTruck(Truck* aTruck) {
    _trucks.push_back(aTruck);
}

// Detach a truck from the farm
void FarmUnit::detachTruck(Truck* aTruck) {
    _trucks.erase(std::remove(_trucks.begin(), _trucks.end(), aTruck), _trucks.end());
}

// Notify trucks for any logistics needs
void FarmUnit::notifyTrucks() {
    for (Truck* truck : _trucks) {
        truck->update(this);
    }
}

// Trigger fertilization process
void FarmUnit::triggerFertilization() {
    if (soilState->getName() == "Dry") {
        // Applying fertilizer transitions to fruitful soil
        soilState = new FruitfulSoil();
        cout << "Fertilization applied, soil transitioned to Fruitful." << endl;
    }
    notifyTrucks();
}

// Trigger crop collection process
void FarmUnit::triggerCropCollection() {
    if (currentStorage >= totalCapacity * 0.9) {
        cout << "Storage near capacity, dispatching delivery truck." << endl;
        notifyTrucks();
    }
}

// Simulate the application of fertilizer and transition from DrySoil to FruitfulSoil
void FarmUnit::increaseProduction() {
    if (soilState->getName() == "Dry") {
        triggerFertilization();
    }
}

// Harvest crops from the field based on soil state
void FarmUnit::harvestCrops() {
    soilState->harvestCrops(this);
    currentStorage = 0; // Clear out storage after harvest
}

// Get the remaining capacity after adding crops
int FarmUnit::getLeftoverCapacity() {
    return totalCapacity - currentStorage;
}

// Call a truck for a specific operation (fertilization or crop collection)
void FarmUnit::callTruck(string operation) {
    if (operation == "fertilize") {
        triggerFertilization();
    } else if (operation == "collect") {
        triggerCropCollection();
    }
}

// Simulate buying a truck
void FarmUnit::buyTruck(Truck* truck) {
    attachTruck(truck);
}

// Simulate selling a truck
void FarmUnit::sellTruck(Truck* truck) {
    detachTruck(truck);
}
