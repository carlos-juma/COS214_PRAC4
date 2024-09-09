#include "Barn.h"
#include <iostream>

using namespace std;

// Constructor for Barn
Barn::Barn(string barnName, int capacity, SoilState* soilState)
    : FarmUnit(barnName, capacity, "Crops", soilState), _barnName(barnName), _capacity(capacity), _currentStorage(0) {
}

// Store crops in the barn up to the maximum capacity
void Barn::storeCrops(int aAmount) {
    if (_currentStorage + aAmount <= _capacity) {
        _currentStorage += aAmount;
        cout << aAmount << " units of crops stored in " << _barnName << ". Current storage: " << _currentStorage << "/" << _capacity << endl;
    } else {
        cout << "Not enough capacity in " << _barnName << ". Storing up to max capacity." << endl;
        _currentStorage = _capacity; // Fill up to capacity
    }
}

// Retrieve crops from the barn, ensuring we don't retrieve more than available
void Barn::retrieveCrops(int aAmount) {
    if (_currentStorage - aAmount >= 0) {
        _currentStorage -= aAmount;
        cout << aAmount << " units of crops retrieved from " << _barnName << ". Remaining storage: " << _currentStorage << "/" << _capacity << endl;
    } else {
        cout << "Not enough crops to retrieve " << aAmount << " from " << _barnName << ". Emptying storage instead." << endl;
        _currentStorage = 0; // Empty the storage
    }
}

// Return the available capacity in the barn
int Barn::getAvailableCapacity() {
    return _capacity - _currentStorage;
}

// Return the name of the barn
string Barn::getBarnName() {
    return _barnName;
}

// Return the current storage amount in the barn
int Barn::getCurrentStorage() {
    return _currentStorage;
}
