#include "BreadthFirstIterator.h"
#include "FarmUnit.h"

BreadthFirstIterator::BreadthFirstIterator(FarmUnit* rootFarm) {
    _currentFarm = rootFarm;
    _queue.push(rootFarm);
}

FarmUnit* BreadthFirstIterator::firstFarm() {
    if (!_queue.empty()) {
        _currentFarm = _queue.front();
    }
    return _currentFarm;
}

FarmUnit* BreadthFirstIterator::nextFarm() {
    if (_queue.empty()) {
        return nullptr;
    }

    FarmUnit* farm = _queue.front();
    _queue.pop();

    // Add children to the queue for breadth-first traversal
    for (int i = 0; i < farm->getChildrenCount(); ++i) {
        _queue.push(farm->getChild(i));
    }

    _currentFarm = farm;
    return _currentFarm;
}

bool BreadthFirstIterator::isDone() {
    return _queue.empty();
}

FarmUnit* BreadthFirstIterator::currentFarm() {
    return _currentFarm;
}
