#include "DepthFirstIterator.h"
#include "FarmUnit.h"

DepthFirstIterator::DepthFirstIterator(FarmUnit* rootFarm) {
    _currentFarm = rootFarm;
    _stack.push(rootFarm);
}

FarmUnit* DepthFirstIterator::firstFarm() {
    if (!_stack.empty()) {
        _currentFarm = _stack.top();
    }
    return _currentFarm;
}

FarmUnit* DepthFirstIterator::nextFarm() {
    if (_stack.empty()) {
        return nullptr;
    }

    FarmUnit* farm = _stack.top();
    _stack.pop();

    // Add children in reverse order for proper depth-first traversal
    for (int i = farm->getChildrenCount() - 1; i >= 0; --i) {
        _stack.push(farm->getChild(i));
    }

    _currentFarm = farm;
    return _currentFarm;
}

bool DepthFirstIterator::isDone() {
    return _stack.empty();
}

FarmUnit* DepthFirstIterator::currentFarm() {
    return _currentFarm;
}
