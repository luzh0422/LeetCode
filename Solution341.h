//
// Created by luzh on 2021/3/23.
//

#ifndef LEETCODE_SOLUTION341_H
#define LEETCODE_SOLUTION341_H

#include <vector>

using namespace std;

class NestedInteger {
public:
    NestedInteger();
    NestedInteger(int num);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    NestedInteger(vector<NestedInteger> nums);
    bool isInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;

private:
    bool mIsInteger;
    int mNum;
    vector<NestedInteger> mNums;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList);


    int next();
    bool hasNext();

private:
    int curr;
    int size;
    vector<NestedInteger> mNestedList;
    NestedIterator* mNestedIterator;
};


#endif //LEETCODE_SOLUTION341_H
