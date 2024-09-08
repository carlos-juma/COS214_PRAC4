#include "SoilState.h"
#include <iostream>

using namespace std;

// Constructor to initialize the soil state with a name
SoilState::SoilState(string name) : _name(name) {}

// Harvest crops based on the current soil state
void SoilState::harvestCrops(Cropfield* cropField) {
    cout << "Harvesting crops with soil state: " << _name << endl;
}

// Simulate rainfall that can affect the soil state
void SoilState::rain(Cropfield* cropField) {
    cout << "Rain affects the soil state: " << _name << endl;
}

// Get the name of the soil state (e.g., "Dry", "Fruitful")
string SoilState::getName() {
    return _name;
}
