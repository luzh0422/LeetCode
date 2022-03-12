//
// Created by luzh on 2021/10/5.
//

#ifndef LEETCODE_SOLUTION284_H
#define LEETCODE_SOLUTION284_H

#include <vector>

using namespace std;


class Iterator {
protected:
    vector<int> mNums;
public:
    Iterator(const vector<int>& nums) {
        mNums = nums;
    };
    // Returns the next element in the iteration.
    virtual int next() = 0;

    // Returns true if the iteration has more elements.
    virtual bool hasNext() const = 0;
};


class PeekingIterator : public Iterator {
    int curr = 0;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {};

    // Returns the next element in the iteration without advancing the iterator.
    int peek();

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next();

    bool hasNext() const;
};


#endif //LEETCODE_SOLUTION284_H
