#include "GreenHouse.h"
#include <iostream>

using namespace std;

// Constructor for GreenHouse
GreenHouse::GreenHouse(std::string name, int totalCapacity, std::string cropType, SoilState* soilState, bool controlledEnvironment)
    : FarmUnit(name, totalCapacity, cropType, soilState), _cropType(cropType), _totalCapacity(totalCapacity), _currentStored(0), _controlledEnvironment(controlledEnvironment) {
}

// Returns the total storage capacity of the greenhouse
int GreenHouse::getTotalCapacity() {
    return this->_totalCapacity;
}

// Returns the type of crop being grown in the greenhouse
std::string GreenHouse::getCropType() {
    return this->_cropType;
}

// Returns the state of the controlled environment
std::string GreenHouse::getEnvironmentState() {
    if (_controlledEnvironment) {
        return "Controlled";
    } else {
        return "Uncontrolled";
    }
}

// Returns the current amount of crops stored in the greenhouse
int GreenHouse::getCurrentStored() {
    return this->_currentStored;
}

// Sets the current amount of crops stored in the greenhouse
void GreenHouse::setCurrentStored(int aAmount) {
    if (aAmount <= _totalCapacity) {
        this->_currentStored = aAmount;
        cout << "Crops stored: " << aAmount << "/" << _totalCapacity << " in " << _cropType << " greenhouse." << endl;
    } else {
        cout << "Cannot store " << aAmount << ". Exceeds greenhouse capacity." << endl;
        this->_currentStored = _totalCapacity;
    }
}

// Setter for _controlledEnvironment
void GreenHouse::setControlledEnvironment(bool controlled) {
    _controlledEnvironment = controlled;
}

// Greenhouse operation to maintain a controlled environment and manage crop growth
void GreenHouse::operation() {
    if (_controlledEnvironment) {
        cout << "Operating in a controlled environment for optimal crop growth in the " << _cropType << " greenhouse." << endl;
    } else {
        cout << "Operating in an uncontrolled environment. Crop growth may be affected in the " << _cropType << " greenhouse." << endl;
    }
}
