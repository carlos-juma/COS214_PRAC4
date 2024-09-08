#include "ExtraGreenHouse.h"
#include <iostream>

using namespace std;

// Increase production by enhancing the total capacity
void ExtraGreenHouse::increaseProduction() {
    cout << "Increasing greenhouse capacity by 15 units." << endl;
    this->_totalCapacity += 15; // Example logic to enhance production by increasing storage capacity
}

// Harvest crops from the greenhouse
void ExtraGreenHouse::harvestCrops() {
    if (this->_currentStored > 0) {
        cout << "Harvesting " << this->_currentStored << " units of crops from the greenhouse." << endl;
        this->_currentStored = 0; // Reset storage after harvest
    } else {
        cout << "No crops to harvest in the greenhouse." << endl;
    }
}

// Return the remaining storage capacity after crops have been stored or harvested
int ExtraGreenHouse::getLeftoverCapacity() {
    return this->_totalCapacity - this->_currentStored;
}

// Return the total capacity of the greenhouse, which can be dynamically enhanced
int ExtraGreenHouse::getTotalCapacity() {
    return this->_totalCapacity;
}
