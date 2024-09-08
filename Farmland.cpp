#include "Farmland.h"
#include "FarmUnit.h"
#include <iostream>

using namespace std;

// Add a FarmUnit to the farmland
void Farmland::addUnit(FarmUnit* unit) {
    _units.push_back(unit);
    cout << "Added a new FarmUnit to the farmland." << endl;
}

// Remove a FarmUnit from the farmland
void Farmland::removeUnit(FarmUnit* unit) {
    for (auto it = _units.begin(); it != _units.end(); ++it) {
        if (*it == unit) {
            _units.erase(it);
            cout << "Removed a FarmUnit from the farmland." << endl;
            break;
        }
    }
}

// Get the total capacity of all units in the farmland
int Farmland::getTotalCapacity() {
    int totalCapacity = 0;
    for (FarmUnit* unit : _units) {
        totalCapacity += unit->getTotalCapacity();  // Assuming FarmUnit has getTotalCapacity method
    }
    return totalCapacity;
}

// Return a specific unit from the farmland by index
FarmUnit* Farmland::getUnit(int index) {
    if (index >= 0 && index < _units.size()) {
        return _units[index];
    }
    return nullptr;
}

// Notify all units in the farmland to start a specified operation (e.g., harvesting or fertilizing)
void Farmland::notifyAllUnits(string operation) {
    for (FarmUnit* unit : _units) {
        if (operation == "harvest") {
            unit->triggerCropCollection();  // Assuming triggerCropCollection exists in FarmUnit
        } else if (operation == "fertilize") {
            unit->triggerFertilization();  // Assuming triggerFertilization exists in FarmUnit
        }
    }
}
