//
// Created by luzehui on 2023/10/30.
//

#include "LeetCode274.h"

int LeetCode274::hIndex(vector<int> &citations) {
    std::sort(citations.begin(), citations.end());
    int n = citations.size();
    int left = 0, right = citations.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (citations[middle] >= (n - middle)) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return n - left;
}
