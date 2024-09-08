#include "GreenHouse.h"
#include <iostream>

using namespace std;

// Returns the total storage capacity of the greenhouse
int GreenHouse::getTotalCapacity() {
    return this->_totalCapacity;
}

// Returns the type of crop being grown in the greenhouse
string GreenHouse::getCropType() {
    return this->_cropType;
}

// Returns the state of the controlled environment (e.g., whether the environment is controlled or not)
string GreenHouse::getEnvironmentState() {
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

// Greenhouse operation to maintain a controlled environment and manage crop growth
void GreenHouse::operation() {
    if (_controlledEnvironment) {
        cout << "Operating in a controlled environment for optimal crop growth in the " << _cropType << " greenhouse." << endl;
    } else {
        cout << "Operating in an uncontrolled environment. Crop growth may be affected in the " << _cropType << " greenhouse." << endl;
    }
}
