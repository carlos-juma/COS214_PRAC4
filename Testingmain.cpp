#include <iostream>
#include <vector>
#include "FarmUnit.h"
#include "Barn.h"
#include "ExtraBarn.h"
#include "DeliveryTruck.h"
#include "FertilizerTruck.h"
#include "FruitfulSoil_.h"
#include "DrySoil_.h"
#include "FloodedSoil_.h"
#include "BreadthFirstIterator.h"
#include "DepthFirstIterator.h"
#include "GreenHouse.h"
#include "ExtraGreenHouse.h"
#include "Farmland.h"
#include "FertilizeField.h"

using namespace std;

void testFarmUnit() {
    cout << "\n=== Testing FarmUnit ===\n";
    SoilState* fruitfulSoil = new FruitfulSoil_();
    FarmUnit* farm = new FarmUnit("Test Farm", 100, "Wheat", fruitfulSoil);

    cout << "Farm name: " << farm->getName() << endl;
    cout << "Total capacity: " << farm->getTotalCapacity() << endl;
    if(farm->getCurrentStorage() > 0){
    cout << "Current storage: " << farm->getCurrentStorage() << endl;
    }
    cout << "Soil state: " << farm->getSoilStateName() << endl;

    farm->harvestCrops();
    farm->triggerCropCollection();
    farm->triggerFertilization();
}

void testSoilStates() {
    cout << "\n=== Testing SoilState Classes ===\n";

    // Test FruitfulSoil_
    SoilState* fruitfulSoil = new FruitfulSoil_();
    Cropfield* cropfield = new Cropfield("Wheat", 100, fruitfulSoil);
    cout << "Testing FruitfulSoil_...\n";
    fruitfulSoil->harvestCrops(cropfield);
    fruitfulSoil->rain(cropfield);

    // Test DrySoil_
    SoilState* drySoil = new DrySoil_();
    cropfield = new Cropfield("Corn", 80, drySoil);
    cout << "Testing DrySoil_...\n";
    drySoil->harvestCrops(cropfield);
    drySoil->rain(cropfield);

    // Test FloodedSoil_
    SoilState* floodedSoil = new FloodedSoil_();
    cropfield = new Cropfield("Rice", 50, floodedSoil);
    cout << "Testing FloodedSoil_...\n";
    floodedSoil->harvestCrops(cropfield);
    floodedSoil->rain(cropfield);
}

void testTrucks() {
    cout << "\n=== Testing Trucks ===\n";

    SoilState* drySoil = new DrySoil_();
    FarmUnit* farm = new FarmUnit("Test Farm", 200, "Corn", drySoil);

    // Test DeliveryTruck
    DeliveryTruck deliveryTruck("Delivery Truck 1");
    cout << "Testing DeliveryTruck...\n";
    deliveryTruck.update(farm);  // Simulate a truck update

    // Test FertilizerTruck
    FertilizerTruck fertilizerTruck("Fertilizer Truck 1");
    cout << "Testing FertilizerTruck...\n";
    fertilizerTruck.update(farm);  // Simulate a truck update
}

void testIterator() {
    cout << "\n=== Testing Iterators (BreadthFirst & DepthFirst) ===\n";

    // Create a simple farm unit hierarchy
    SoilState* fruitfulSoil = new FruitfulSoil_();
    FarmUnit* mainFarm = new FarmUnit("Main Farm", 300, "Wheat", fruitfulSoil);
    FarmUnit* childFarm1 = new FarmUnit("Child Farm 1", 150, "Corn", fruitfulSoil);
    FarmUnit* childFarm2 = new FarmUnit("Child Farm 2", 180, "Soy", fruitfulSoil);

    // Add child farms
    mainFarm->addChild(childFarm1);
    mainFarm->addChild(childFarm2);

    // Test Breadth-First Iterator
    cout << "\nBreadth-First Iterator:\n";
    BreadthFirstIterator bfs(mainFarm);
    while (!bfs.isDone()) {
        cout << "Visiting: " << bfs.currentFarm()->getName() << endl;
        bfs.nextFarm();
    }

    // Test Depth-First Iterator
    cout << "\nDepth-First Iterator:\n";
    DepthFirstIterator dfs(mainFarm);
    while (!dfs.isDone()) {
        cout << "Visiting: " << dfs.currentFarm()->getName() << endl;
        dfs.nextFarm();
    }
}

// Function to test Barn and ExtraBarn
void testBarns() {
    cout << "\n=== Testing Barn and ExtraBarn ===\n";

    // Create Barn
    SoilState* fruitfulSoil = new FruitfulSoil_();
    Barn* barn = new Barn("Main Barn", 100, fruitfulSoil);
    barn->storeCrops(50);  // Store 50 units
    barn->retrieveCrops(20);  // Retrieve 20 units
    barn->storeCrops(80);  // Try to store 80 (exceeds capacity)

    // Create ExtraBarn
    ExtraBarn* extraBarn = new ExtraBarn("Extra Barn", 80, fruitfulSoil);
    extraBarn->storeCrops(60);  // Store 60 units
    extraBarn->increaseProduction();  // Increase capacity
    extraBarn->storeCrops(30);  // Store another 30 units after capacity increase
    extraBarn->harvestCrops();  // Harvest all crops from ExtraBarn
}
void testGreenHouse() {
    SoilState* fruitfulSoil = new FruitfulSoil_();  // Assuming SoilState and FruitfulSoil_ exist
    GreenHouse* vegetableGreenhouse = new GreenHouse("Vegetable Greenhouse", 100, "Vegetables", fruitfulSoil, true);

    cout << "GreenHouse name: " << vegetableGreenhouse->getName() << endl;
    cout << "Initial environment state: " << vegetableGreenhouse->getEnvironmentState() << endl;

    // Test setting controlled environment
    vegetableGreenhouse->setControlledEnvironment(false);
    cout << "Updated environment state: " << vegetableGreenhouse->getEnvironmentState() << endl;

    vegetableGreenhouse->setCurrentStored(50);  // Store some crops
    vegetableGreenhouse->operation();  // Perform operation based on the environment
}
void testCropfield() {
    cout << "\n=== Testing Cropfield ===\n";

    SoilState* drySoil = new DrySoil_();
    Cropfield* cornField = new Cropfield("Corn", 100, drySoil);

    // Test storing crops within capacity
    cornField->storeCrops(50);
    cout << "Remaining capacity: " << cornField->getLeftoverCapacity() << endl;

    // Test exceeding capacity
    cornField->storeCrops(60);  // This should not exceed total capacity
    cout << "Remaining capacity after overstore: " << cornField->getLeftoverCapacity() << endl;

    // Test applying fertilizer and increasing production
    cornField->applyFertilizer();
    cout << "Soil state after fertilization: " << cornField->getSoilStateName() << endl;

    cornField->increaseProduction();
    cout << "New total capacity: " << cornField->getTotalCapacity() << endl;
}

void testExtraGreenHouse() {
    SoilState* fruitfulSoil = new FruitfulSoil_(); // Assuming you have a valid SoilState subclass

    // Creating an ExtraGreenHouse object with the required parameters
    ExtraGreenHouse* greenHouse = new ExtraGreenHouse("Extra Greenhouse", 150, "Tomatoes", fruitfulSoil, true);
    
    greenHouse->increaseProduction(); // Testing increasing production
    greenHouse->harvestCrops();       // Testing harvesting crops

    delete greenHouse;  // Don't forget to free the memory
    delete fruitfulSoil;
}

void testFarmland() {
    SoilState* fruitfulSoil = new FruitfulSoil_(); // Assuming you have a valid SoilState subclass

    // Creating a Farmland object with the required parameters
    Farmland* farmland = new Farmland("Main Farmland", 500, "Mixed Crops", fruitfulSoil);
    
    // Add farm units
    FarmUnit* field1 = new Cropfield("Wheat", 200, fruitfulSoil);
    FarmUnit* field2 = new Cropfield("Corn", 150, fruitfulSoil);

    farmland->addUnit(field1);
    farmland->addUnit(field2);

    cout << "Total capacity of farmland: " << farmland->getTotalCapacity() << endl;

    // Notify all units about a harvest operation
    farmland->notifyAllUnits("harvest");

    delete field1;
    delete field2;
    delete farmland;
    delete fruitfulSoil;
}
void testZvesezveseFarm() {
    cout << "=== Zvesezvese Farm Composite Pattern Demonstration ===" << endl;

    // Create the soil states
    SoilState* drySoil = new DrySoil_();
    SoilState* fruitfulSoil = new FruitfulSoil_();
    SoilState* floodedSoil = new FloodedSoil_();

    // Create crop fields with different soil states and crop types
    Cropfield* wheatField = new Cropfield("Wheat", 100, drySoil);  // Wheat in DrySoil
    Cropfield* cornField = new Cropfield("Corn", 120, fruitfulSoil);  // Corn in FruitfulSoil
    Cropfield* riceField = new Cropfield("Rice", 150, floodedSoil);  // Rice in FloodedSoil

    // Create a farm (Farmland) and add the crop fields (Composite pattern)
    Farmland* ZvesezveseFarm = new Farmland("Zvesezvese Farm", 0, "", nullptr);
    ZvesezveseFarm->addUnit(wheatField);
    ZvesezveseFarm->addUnit(cornField);
    ZvesezveseFarm->addUnit(riceField);

    // Traverse the farm and check crop details
    cout << "Traversing the Zvesezvese Farm:" << endl;
    for (int i = 0; i < ZvesezveseFarm->getChildrenCount(); ++i) {
        FarmUnit* field = ZvesezveseFarm->getChild(i);
        cout << "Field: " << field->getName() << ", Crop Type: " << dynamic_cast<Cropfield*>(field)->getCropType()
             << ", Soil State: " << field->getSoilStateName() << ", Capacity: " << field->getTotalCapacity() << endl;
    }

    // Apply fertilizer to the wheat field (DrySoil -> FruitfulSoil)
    cout << "\nApplying fertilizer to the Wheat field..." << endl;
    wheatField->applyFertilizer();
    cout << "Wheat field's new soil state: " << wheatField->getSoilStateName() << endl;

    // Harvest crops in the corn field (already fruitful)
    cout << "\nHarvesting the Corn field..." << endl;
    cornField->harvestCrops();

    // Increase the storage capacity of the rice field by adding an ExtraBarn
    cout << "\nAdding Extra Barn to the Rice field..." << endl;
    riceField->increaseProduction();
    cout << "Rice field's new total capacity: " << riceField->getTotalCapacity() << endl;

    // Simulate notifying the trucks (logistics management)
    DeliveryTruck deliveryTruck("Delivery Truck");
    FertilizerTruck fertilizerTruck("Fertilizer Truck");

    // Notify the trucks based on the state of the fields
    cout << "\nNotifying trucks for logistics..." << endl;
    deliveryTruck.update(riceField);  // Rice field might be full
    fertilizerTruck.update(wheatField);  // Wheat field after fertilization
}
void testDecoratorPattern() {
    cout << "\n=== Testing Decorator Pattern (FertilizeField and ExtraBarn) ===\n";

    // 1. Create a Cropfield with Dry soil and limited capacity
    SoilState* drySoil = new DrySoil_();
    Cropfield* wheatField = new Cropfield("Wheat", 50, drySoil);

    cout << "Initial setup: Wheat Field with Dry Soil and a capacity of " << wheatField->getTotalCapacity() << " tonnes.\n";
    
    // Store some crops
    wheatField->storeCrops(30);
    cout << "Current stored crops: " << wheatField->getCurrentStorage() << " tonnes.\n";

    // 2. Apply Fertilizer (Decorator) to improve the soil from Dry to Fruitful
    cout << "\nApplying Fertilizer...\n";
    FertilizeField* fertilizedWheatField = new FertilizeField(wheatField);  // Applying fertilizer

    // 3. Add an ExtraBarn (Decorator) to increase storage capacity
    cout << "\nAdding Extra Barn for increased storage...\n";
  ExtraBarn* extendedWheatField = new ExtraBarn(fertilizedWheatField->getName(), fertilizedWheatField->getTotalCapacity(), fertilizedWheatField->getSoilState());


    extendedWheatField->increaseProduction();  // Increases the total capacity

    cout << "New total capacity after adding extra barn: " << extendedWheatField->getTotalCapacity() << " tonnes.\n";

    // 4. Store more crops after increasing storage capacity
    extendedWheatField->storeCrops(40);  // Attempt to store 40 more tonnes
    cout << "Current stored crops after adding more: " << extendedWheatField->getCurrentStorage() << " tonnes.\n";

    // 5. Harvest crops (should reflect the fruitful soil and increased storage capacity)
    cout << "\nHarvesting crops after all enhancements...\n";
    extendedWheatField->harvestCrops();

    // Clean up (optional but good practice)
    delete extendedWheatField;
    delete fertilizedWheatField;
    delete wheatField;
    delete drySoil;
}
void testSoilStatePattern() {
    cout << "\n=== Testing Soil State Pattern ===\n";

    // 1. Create a crop field with initial DrySoil state
    SoilState* drySoil = new DrySoil_();
    Cropfield* wheatField = new Cropfield("Wheat", 100, drySoil);

    cout << "Initial state: " << wheatField->getSoilStateName() << endl;
    wheatField->harvestCrops();
    cout << "Remaining capacity: " << wheatField->getLeftoverCapacity() << " tonnes after harvest.\n";

    // 2. Simulate rain (transition from Dry to Fruitful)
    cout << "\nSimulating rain...\n";
    wheatField->applyFertilizer();  // This simulates the soil improving to a Fruitful state
    cout << "New state after rain: " << wheatField->getSoilStateName() << endl;
    wheatField->harvestCrops();
    cout << "Remaining capacity: " << wheatField->getLeftoverCapacity() << " tonnes after harvest.\n";

    // 3. Manually switch to FloodedSoil to simulate flooding
    cout << "\nSimulating flood...\n";
    SoilState* floodedSoil = new FloodedSoil_();
    wheatField->applyFertilizer();  // Change soil state to Flooded
    cout << "New state after flood: " << floodedSoil->getName() << endl;
    wheatField->harvestCrops();
    cout << "Remaining capacity: " << wheatField->getLeftoverCapacity() << " tonnes after harvest.\n";

    // Cleanup
    delete wheatField;
    delete floodedSoil;
}
// void testObserverPattern() {
//     cout << "\n=== Testing Observer Pattern ===\n";

//     // Create a farm unit (crop field)
//     SoilState* fruitfulSoil = new FruitfulSoil_();
//     Cropfield* wheatField = new Cropfield("Wheat", 100, fruitfulSoil);

//     // Create two trucks (observers)
//     FertilizerTruck* fertilizerTruck = new FertilizerTruck("Fertilizer Truck 1");
//     DeliveryTruck* deliveryTruck = new DeliveryTruck("Delivery Truck 1");

//     // Attach trucks to the farm unit
//     wheatField->attachTruck(fertilizerTruck);
//     wheatField->attachTruck(deliveryTruck);

//     // Simulate a crop harvest, which will notify all attached trucks
//     cout << "\nSimulating crop harvest...\n";
//     wheatField->harvestCrops();  // Triggers truck notifications

//     // Detach the delivery truck and notify again
//     cout << "\nDetaching Delivery Truck and notifying again...\n";
//     wheatField->detachTruck(deliveryTruck);
//     wheatField->harvestCrops();  // Now only the fertilizer truck should respond

//     // Clean up (optional)
//     delete fertilizerTruck;
//     delete deliveryTruck;
//     delete wheatField;
//     delete fruitfulSoil;
// }
void testObserverPattern() {
    cout << "\n=== Testing Observer Pattern ===\n";
    SoilState* drySoil = new DrySoil_();  // Assuming DrySoil_ exists
    FarmUnit* wheatField = new FarmUnit("Wheat Field", 100, "Wheat", drySoil);

    // Create trucks (observers)
    FertilizerTruck* fertilizerTruck = new FertilizerTruck("Fertilizer Truck");
    DeliveryTruck* deliveryTruck = new DeliveryTruck("Delivery Truck");

    // Attach trucks to the farm unit
    wheatField->attachTruck(fertilizerTruck);
    wheatField->attachTruck(deliveryTruck);

    // Perform actions that notify trucks
    wheatField->harvestCrops();  // Both trucks should be notified

    // Detach delivery truck and perform another action
    wheatField->detachTruck(deliveryTruck);
    wheatField->triggerFertilization();  // Only the fertilizer truck should be notified
}
void testIteratorPattern() {
    cout << "=== Testing Iterator Pattern ===" << endl;

    // Create some farm units (root farm and child farms)
    FarmUnit* rootFarm = new FarmUnit("Main Farm", 1000, "Wheat", nullptr);
    FarmUnit* childFarm1 = new FarmUnit("Child Farm 1", 500, "Corn", nullptr);
    FarmUnit* childFarm2 = new FarmUnit("Child Farm 2", 300, "Barley", nullptr);
    FarmUnit* grandChildFarm = new FarmUnit("Grandchild Farm", 200, "Soybeans", nullptr);

    // Construct the farm hierarchy
    rootFarm->addChild(childFarm1);
    rootFarm->addChild(childFarm2);
    childFarm1->addChild(grandChildFarm);

    // Test Breadth-First Iterator
    cout << "--- Breadth-First Traversal ---" << endl;
    BreadthFirstIterator bfIterator(rootFarm);
    for (FarmUnit* farm = bfIterator.firstFarm(); !bfIterator.isDone(); farm = bfIterator.nextFarm()) {
        cout << "Visiting: " << farm->getName() << endl;
    }

    // Test Depth-First Iterator
    cout << "--- Depth-First Traversal ---" << endl;
    DepthFirstIterator dfIterator(rootFarm);
    for (FarmUnit* farm = dfIterator.firstFarm(); !dfIterator.isDone(); farm = dfIterator.nextFarm()) {
        cout << "Visiting: " << farm->getName() << endl;
    }

    // Clean up (free memory)
    delete grandChildFarm;
    delete childFarm2;
    delete childFarm1;
    delete rootFarm;

    cout << "=== End of Iterator Pattern Test ===" << endl;
}
int main() {
testFarmUnit();
testSoilStates();
testTrucks();
testIterator();
testBarns();
testGreenHouse();
testCropfield();
testExtraGreenHouse();
testFarmland();
testZvesezveseFarm();
testDecoratorPattern();
testSoilStatePattern();
testObserverPattern();
testIteratorPattern();
    return 0;
}
