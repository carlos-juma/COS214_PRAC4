#include "DeliveryTruck.h"
#include <iostream>

using namespace std;

void DeliveryTruck::update(FarmUnit* unit) {
    cout << "DeliveryTruck [" << getName() << "] notified by farm unit: " << unit->getName() << endl;
    if (unit->getTotalCapacity() - unit->getCurrentStorage() <= 10) {
        cout << "Storage nearing full. Collecting crops." << endl;
        startEngine();
        unit->triggerCropCollection();
    } else {
        cout << "No need to collect crops." << endl;
    }
}
