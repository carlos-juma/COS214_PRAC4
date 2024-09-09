#include "SoilState.h"
#include <iostream>

using namespace std;

SoilState::SoilState(string name) : name(name) {}

std::string SoilState::getName() const {
    return name;
}
