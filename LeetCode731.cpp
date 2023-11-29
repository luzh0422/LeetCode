//
// Created by 陆泽辉 on 2022/7/19.
//

#include "LeetCode731.h"

MyCalendarTwo::MyCalendarTwo() {
    storesOne = {};
    storesTwo = {};
}

bool MyCalendarTwo::book(int start, int end) {
    for (pair<int, int>& p : storesTwo) {
        int start1 = p.first, end1 = p.second;
        if (!(start1 >= end || end1 <= start)) {
            return false;
        }
    }
    for (pair<int, int>& p : storesOne) {
        int start1 = p.first, end1 = p.second;
        if (!(start1 >= end || end1 <= start)) {
            int start2 = max(start, start1);
            int end2 = min(end, end1);
            storesTwo.push_back({start2, end2});
        }
    }
    storesOne.push_back({start, end});
    return true;
}
