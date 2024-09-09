#ifndef __FERTILIZEFIELD_H__
#define __FERTILIZEFIELD_H__

#include "Cropfield.h"

class FertilizeField : public Cropfield {
public:
    FertilizeField(Cropfield* baseField);  // Constructor to apply fertilizer to an existing field
    void increaseProduction();             // Increases production by applying fertilizer
    void harvestCrops() override;          // Overrides the harvest function
    std::string getSoilStateName();        // Get the current soil state name
};

#endif
