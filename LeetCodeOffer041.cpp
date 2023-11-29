//
// Created by 陆泽辉 on 2022/7/16.
//

#include "LeetCodeOffer041.h"

MovingAverage::MovingAverage(int size) {
    distance = size;
}

double MovingAverage::next(int val) {
    currDis++;
    if (currDis > distance) {
        sum -= nums[index];
        nums[index] = val;
        index = (index + 1) % distance;
    } else {
        nums.push_back(val);
    }
    sum += val;
    double ret = double(sum) / double(min(distance, currDis));
    return ret;
}
