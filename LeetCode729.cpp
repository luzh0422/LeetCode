//
// Created by 陆泽辉 on 2022/7/5.
//

#include "LeetCode729.h"

MyCalendar::MyCalendar() {
    calendar = {};
    starts = {};
    ends = {};
}

bool MyCalendar::book(int start, int end) {
    if (starts.empty()) {
        starts.push_back(start);
        ends.push_back(end);
        return true;
    }
    int index = binarySearch(starts, end);
    if (index == 0) {
        starts.insert(starts.begin(), start);
        ends.insert(ends.begin(), end);
        return true;
    } else {
        if (index == -1 && ends.back() > start || ends[index - 1] > start) {
            return false;
        } else {
            starts.insert(starts.begin() + index, start);
            ends.insert(ends.begin() + index, end);
            return true;
        }
    }
}

int MyCalendar::binarySearch(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (arr[middle] >= target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    if (right != -1 && arr[right] >= target) {
        return right;
    } else {
        return arr.size();
    }
}
