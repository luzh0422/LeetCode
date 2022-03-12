//
// Created by luzh on 2021/10/5.
//

#include "Solution284.h"

bool PeekingIterator::hasNext() const {
    return curr < mNums.size();
}

int PeekingIterator::next() {
    return mNums[curr++];
}

int PeekingIterator::peek() {
    return mNums[curr];
}
