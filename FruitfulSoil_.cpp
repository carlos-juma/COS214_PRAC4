#include "FruitfulSoil_.h"
#include "Cropfield.h"
#include <iostream>

using namespace std;

// Constructor for FruitfulSoil
FruitfulSoil_::FruitfulSoil_() {
    this->_name = "Fruitful";
}

// Harvest crops based on fruitful soil state
void FruitfulSoil_::harvestCrops(Cropfield* cropField) {
    cout << "Harvesting crops in fruitful soil. Yield is 3x." << endl;
    int currentStorage = cropField->getCurrentStored();  // Assuming Cropfield has getCurrentStored() method
    int newYield = currentStorage * 3;                   // Triple the crop yield
    cropField->setCurrentStored(newYield);               // Update the crop storage with the enhanced yield
    cout << "Total harvested: " << newYield << " units of crops." << endl;
}

// Simulate rain for fruitful soil
void FruitfulSoil_::rain(Cropfield* cropField) {
    cout << "Rain enhances the fruitful soil further." << endl;
    
    // Logic to further improve the soil conditions or maintain fertility
    int currentStorage = cropField->getCurrentStored();
    int bonusYield = currentStorage * 0.2; // Assuming rain increases yield by 20%
    cropField->setCurrentStored(currentStorage + bonusYield); // Increase storage
    cout << "Rain added an additional " << bonusYield << " units of crops." << endl;
}

// Get the name of this soil state
string FruitfulSoil_::getName() {
    return _name;
}
