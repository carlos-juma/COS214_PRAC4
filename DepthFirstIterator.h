#ifndef __DepthFirstIterator_h__
#define __DepthFirstIterator_h__

#include "FarmIterator.h"
#include <stack>

class FarmUnit;

class DepthFirstIterator : public FarmIterator {
private:
    std::stack<FarmUnit*> _stack;
    FarmUnit* _currentFarm;  // Track current farm

public:
    DepthFirstIterator(FarmUnit* rootFarm);

    FarmUnit* firstFarm() override;
    FarmUnit* nextFarm() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
