#ifndef __GreenHouse_h__
#define __GreenHouse_h__

#include <string>
#include "FarmUnit.h"

class GreenHouse : public FarmUnit
{
protected:
    std::string _cropType;
    int _totalCapacity;
    int _currentStored;
    bool _controlledEnvironment;

public:
    // Constructor for GreenHouse
    GreenHouse(std::string name, int totalCapacity, std::string cropType, SoilState* soilState, bool controlledEnvironment);

    int getTotalCapacity();
    std::string getCropType();
    std::string getEnvironmentState();
    int getCurrentStored();
    void setCurrentStored(int aAmount);
    void operation();

    // Setter for _controlledEnvironment
    void setControlledEnvironment(bool controlled);
};

#endif
