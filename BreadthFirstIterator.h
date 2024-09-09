#ifndef __BreadthFirstIterator_h__
#define __BreadthFirstIterator_h__

#include "FarmIterator.h"
#include <queue>

class FarmUnit;

class BreadthFirstIterator : public FarmIterator {
private:
    std::queue<FarmUnit*> _queue;
    FarmUnit* _currentFarm;

public:
    BreadthFirstIterator(FarmUnit* rootFarm);

    FarmUnit* firstFarm() override;
    FarmUnit* nextFarm() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
