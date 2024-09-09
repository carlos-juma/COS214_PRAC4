#include "Farmland.h"
#include "FarmUnit.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Add a new FarmUnit to the Farmland
void Farmland::addUnit(FarmUnit* unit) {
    _units.push_back(unit);
    cout << "Added a new FarmUnit to the farmland." << endl;
}

// Remove a FarmUnit from the Farmland
void Farmland::removeUnit(FarmUnit* unit) {
    auto it = find(_units.begin(), _units.end(), unit);
    if (it != _units.end()) {
        _units.erase(it);
        cout << "Removed a FarmUnit from the farmland." << endl;
    }
}

// Calculate the total capacity of the farmland by summing up the capacities of all units
int Farmland::getTotalCapacity() {
    int totalCapacity = 0;
    for (FarmUnit* unit : _units) {
        totalCapacity += unit->getTotalCapacity();
    }
    return totalCapacity;
}

// Get a specific FarmUnit by its index
FarmUnit* Farmland::getUnit(int index) {
    if (index >= 0 && index < _units.size()) {
        return _units[index];
    }
    return nullptr;
}

// Notify all units about an operation (e.g., harvest or fertilize)
void Farmland::notifyAllUnits(string operation) {
    for (FarmUnit* unit : _units) {
        if (operation == "harvest") {
            unit->triggerCropCollection();  // Trigger crop collection for each unit
        } else if (operation == "fertilize") {
            unit->triggerFertilization();   // Trigger fertilization for each unit
        }
    }
}
