//
// Created by luzh on 2021/8/27.
//

#include "Solution295.h"

MedianFinder::MedianFinder() {

}

/**
 * 要记住upper_bound是找大于查找数的位置；lower_bound是找大于等于查找数的位置；
 * @param num
 */
void MedianFinder::addNum(int num) {
    auto it = upper_bound(nums.begin(), nums.end(), num);
    if (it == nums.end()) {
        nums.push_back(num);
        size += 1;
    } else {
        nums.insert(it, num);
        size += 1;
    }
    return;
}

double MedianFinder::findMedian() {
    if (size == 0) {
        return 0;
    }
    if (size % 2 == 0) {
        return double(nums[size / 2 - 1] + nums[size / 2]) / 2;
    } else {
        return double(nums[size / 2]);
    }
}
