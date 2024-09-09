#ifndef __FarmIterator_h__
#define __FarmIterator_h__

class FarmUnit;

class FarmIterator {
public:
    virtual ~FarmIterator() = default;
    virtual FarmUnit* firstFarm() = 0;
    virtual FarmUnit* nextFarm() = 0;
    virtual bool isDone() = 0;
    virtual FarmUnit* currentFarm() = 0;
};

#endif
