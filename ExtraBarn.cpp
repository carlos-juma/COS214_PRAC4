#include "ExtraBarn.h"
#include <iostream>

using namespace std;

// Increase production by enhancing capacity
void ExtraBarn::increaseProduction() {
    cout << "Increasing barn capacity by 20 units." << endl;
    this->_capacity += 20; // Example logic to enhance production by increasing storage capacity
}

// Harvest crops from the barn
void ExtraBarn::harvestCrops() {
    if (this->_currentStorage > 0) {
        cout << "Harvesting " << this->_currentStorage << " units of crops from the barn." << endl;
        this->_currentStorage = 0; // Reset storage after harvest
    } else {
        cout << "No crops to harvest in the barn." << endl;
    }
}

// Return the remaining storage capacity after adding the extra barn
int ExtraBarn::getLeftoverCapacity() {
    return this->_capacity - this->_currentStorage;
}

// Return the total capacity of the barn after potential upgrades
int ExtraBarn::getTotalCapacity() {
    return this->_capacity;
}
