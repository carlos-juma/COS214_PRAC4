#include "FruitfulSoil_.h"
#include "Cropfield.h"
#include <iostream>

using namespace std;

FruitfulSoil_::FruitfulSoil_() : SoilState("Fruitful") {}

void FruitfulSoil_::harvestCrops(Cropfield* cropField) {
    cout << "Harvesting crops in fruitful soil. Yield is 3x." << endl;
    int currentStorage = cropField->getCurrentStorage();
    int newYield = currentStorage * 3;
    cropField->storeCrops(newYield);
    cout << "Total harvested: " << newYield << " units of crops." << endl;
}

void FruitfulSoil_::rain(Cropfield* cropField) {
    cout << "Rain enhances the fruitful soil." << endl;
    int currentStorage = cropField->getCurrentStorage();
    int bonusYield = currentStorage * 0.2;
    cropField->storeCrops(currentStorage + bonusYield);
    cout << "Rain added " << bonusYield << " units of crops." << endl;
}

std::string FruitfulSoil_::getName() const {
    return SoilState::getName();
}
