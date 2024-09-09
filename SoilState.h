#ifndef __SoilState_h__
#define __SoilState_h__

#include <string>
class Cropfield;

class SoilState {
protected:
    std::string name;
public:
    SoilState(std::string name);
    virtual void harvestCrops(Cropfield* cropField) = 0;  // Pure virtual method
    virtual void rain(Cropfield* cropField) = 0;          // Pure virtual method
    virtual std::string getName() const;  // To get the name of the soil state
};

#endif
