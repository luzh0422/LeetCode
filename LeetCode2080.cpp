//
// Created by luzehui on 25-2-18.
//

#include "LeetCode2080.h"

RangeFreqQuery::RangeFreqQuery(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        record[arr[i]].push_back(i);
    }
}

int RangeFreqQuery::query(int left, int right, int value) {
    if (!record.count(value)) {
        return 0;
    }
    int leftIndex = greaterOrEqualNum(record[value], left);
    int rightIndex = lessOrEqualNum(record[value], right);
    if (record[value][leftIndex] > right || record[value][rightIndex] < left) {
        return 0;
    }
    return rightIndex - leftIndex + 1;
}

int RangeFreqQuery::lessOrEqualNum(vector<int> &arr, int value) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int middle = (left + right + 1) / 2;
        if (arr[middle] > value) {
            right = middle - 1;
        } else {
            left = middle;
        }
    }
    return left;
}

int RangeFreqQuery::greaterOrEqualNum(vector<int> &arr, int value) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (arr[middle] >= value) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return right;
}

