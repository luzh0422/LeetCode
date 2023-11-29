//
// Created by luzehui on 2023/11/29.
//

#include "LeetCode2336.h"

SmallestInfiniteSet::SmallestInfiniteSet() {

}

void SmallestInfiniteSet::addBack(int num) {
    if (num < curr_) {
        minVals.insert(num);
    }
}

int SmallestInfiniteSet::popSmallest() {
    int val;
    if (!minVals.empty()) {
        val = *minVals.begin();
        minVals.erase(minVals.begin());
    } else {
        val = curr_;
        curr_++;
    }
    return val;
}