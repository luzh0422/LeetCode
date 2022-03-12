//
// Created by luzh on 2021/8/27.
//

#ifndef LEETCODE_SOLUTION295_H
#define LEETCODE_SOLUTION295_H

#include <vector>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder();

    void addNum(int num);

    double findMedian();

private:
    vector<int> nums = {};
    int size = 0;
};

#endif //LEETCODE_SOLUTION295_H
