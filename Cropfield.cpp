#include "Cropfield.h"
#include "FruitfulSoil_.h"
#include <iostream>

using namespace std;

// Constructor to initialize the crop field
Cropfield::Cropfield(string cropType, int totalCapacity, SoilState* soilState)
    : FarmUnit(cropType, totalCapacity, cropType, soilState), cropType(cropType), totalCapacity(totalCapacity), soilState(soilState), currentStorage(0) {}


// Harvest crops based on the current soil state
void Cropfield::harvestCrops() {
    if (totalCapacity > 0) {
        cout << "Harvesting crops from the field with soil state: " << soilState->getName() << endl;
        double yieldMultiplier = 1;

        if (soilState->getName() == "Fruitful") {
            yieldMultiplier = 3.0;  // Fruitful soil yields 3x
        } else if (soilState->getName() == "Dry") {
            yieldMultiplier = 1.0;  // Dry soil yields normal
        } else if (soilState->getName() == "Flooded") {
            yieldMultiplier = 0.0;  // No crops can be harvested in flooded soil
        }

        double harvestedTonnes = totalCapacity * yieldMultiplier;  // Harvested amount in tonnes
        cout << "Harvesting crops in " << soilState->getName() << " soil. Yield is " << yieldMultiplier << "x." << endl;
        cout << "Total harvested: " << harvestedTonnes << " tonnes of crops." << endl;

        // Ensure current storage doesn't exceed total capacity
        if (harvestedTonnes > totalCapacity) {
            currentStorage = totalCapacity;
        } else {
            currentStorage = harvestedTonnes;
        }
        
        cout << "Updated storage after harvest: " << currentStorage << " tonnes of crops." << endl;

    } else {
        cout << "No crops to harvest in the field." << endl;
    }
}


// Apply fertilizer to the crop field and transition from DrySoil to FruitfulSoil
void Cropfield::applyFertilizer() {
    cout << "Applying fertilizer to the crop field." << endl;
    if (soilState->getName() == "Dry") {
        soilState = new FruitfulSoil_();
        cout << "Soil state transitioned from Dry to Fruitful." << endl;
    }
}

std::string Cropfield::getSoilStateName() {
    return soilState->getName();
}

std::string Cropfield::getCropType() {
    return cropType;
}

int Cropfield::getTotalCapacity() {
    return totalCapacity;
}
SoilState* Cropfield::getSoilState() {
    return soilState;
}

void Cropfield::increaseProduction() {
    if (soilState->getName() == "Dry") {
        applyFertilizer(); 
    } else if (soilState->getName() == "Fruitful") {
        totalCapacity += 10;
    }
}

int Cropfield::getLeftoverCapacity() {
    return totalCapacity - currentStorage;
}

void Cropfield::storeCrops(int amount) {
    if (currentStorage + amount <= totalCapacity) {
        currentStorage += amount;
    } else {
        cout << "Not enough capacity, storing up to max capacity." << endl;
        currentStorage = totalCapacity;
    }
}
