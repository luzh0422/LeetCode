//
// Created by 陆泽辉 on 2022/4/15.
//

#ifndef LEETCODE_LEETCODE385_H
#define LEETCODE_LEETCODE385_H

#include <vector>
#include <string>
#include "Solution341.h"

using namespace std;
//
//class NestedInteger {
//public:
//    // Constructor initializes an empty nested list.
//    NestedInteger();
//
//    // Constructor initializes a single integer.
//    NestedInteger(int value);
//
//    // Return true if this NestedInteger holds a single integer, rather than a nested list.
//    bool isInteger() const;
//
//    // Return the single integer that this NestedInteger holds, if it holds a single integer
//    // The result is undefined if this NestedInteger holds a nested list
//    int getInteger() const;
//
//    // Set this NestedInteger to hold a single integer.
//    void setInteger(int value);
//
//    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//    void add(const NestedInteger &ni);
//
//    // Return the nested list that this NestedInteger holds, if it holds a nested list
//    // The result is undefined if this NestedInteger holds a single integer
//    const vector<NestedInteger> &getList() const;
//
//private:
//    int mVal;
//    vector<NestedInteger> mList;
//};
class LeetCode385 {
public:
    NestedInteger deserialize(string s);

private:
    NestedInteger deserialize(string s, int currId);
};


#endif //LEETCODE_LEETCODE385_H
