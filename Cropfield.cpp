#include "Cropfield.h"
#include "SoilState.h"
#include <iostream>

using namespace std;

// Constructor to initialize the crop field
Cropfield::Cropfield(string cropType, int totalCapacity, SoilState* soilState)
    : _cropType(cropType), _totalCapacity(totalCapacity), _soilState(soilState), _currentStorage(0) {}

// Harvest crops based on the current soil state
void Cropfield::harvestCrops() {
    cout << "Harvesting crops from the field with soil state: " << _soilState->getName() << endl;
    // Soil state influences the crop yield
    _soilState->harvestCrops(this);
    _currentStorage = 0; // After harvest, reset storage
}

// Apply fertilizer to the crop field and transition from DrySoil to FruitfulSoil
void Cropfield::applyFertilizer() {
    cout << "Applying fertilizer to the crop field." << endl;
    if (_soilState->getName() == "Dry") {
        // Transition from DrySoil to FruitfulSoil
        _soilState = new FruitfulSoil();
        cout << "Soil state transitioned from Dry to Fruitful." << endl;
    }
}

// Get the name of the current soil state
string Cropfield::getSoilStateName() {
    return _soilState->getName();
}

// Get the crop type being grown in the crop field
string Cropfield::getCropType() {
    return _cropType;
}

// Get the total storage capacity of the crop field
int Cropfield::getTotalCapacity() {
    return _totalCapacity;
}

// Increase production after applying fertilizer or adding additional capacity like ExtraBarn
void Cropfield::increaseProduction() {
    if (_soilState->getName() == "Dry") {
        applyFertilizer(); // Increase production by applying fertilizer
    } else if (_soilState->getName() == "Fruitful") {
        _totalCapacity += 10; // Example: increase capacity after applying fertilizer
    }
}

// Return the remaining storage capacity after adding crops or harvesting
int Cropfield::getLeftoverCapacity() {
    return _totalCapacity - _currentStorage;
}

// Function to simulate adding crops to the field storage
void Cropfield::storeCrops(int amount) {
    if (_currentStorage + amount <= _totalCapacity) {
        _currentStorage += amount;
    } else {
        cout << "Not enough capacity, storing up to max capacity." << endl;
        _currentStorage = _totalCapacity; // Limit to max capacity
    }
}
