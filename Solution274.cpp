//
// Created by luzh on 2021/7/11.
//

#include "Solution274.h"

int Solution274::hIndex(vector<int> &citations) {
    std::sort(citations.begin(), citations.end());
    int size = citations.size();
    int right = citations[size - 1];
    for (int i = 0; i < right; i++) {
        int temp = greaterThanNum(citations, i);
        if (temp == i) {
            return temp;
        }
    }
    return -1;
}

int Solution274::greaterThanNum(vector<int> &citations, int num) {
    int i = 0;
    int size = citations.size();
    for (; citations[i] < num; i++) {}
    return size - i;
}
