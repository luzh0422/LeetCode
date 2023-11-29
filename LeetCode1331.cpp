//
// Created by 陆泽辉 on 2022/7/28.
//

#include "LeetCode1331.h"
#include <unordered_map>

vector<int> LeetCode1331::arrayRankTransform(vector<int> &arr) {
    vector<int> arrCopy(arr.begin(), arr.end());
    std::sort(arrCopy.begin(), arrCopy.end(), less<int>());
    unordered_map<int, int> uSorts;
    int index = 1;
    for (int num : arrCopy) {
        if (!uSorts.count(num)) {
            uSorts.insert(unordered_map<int, int>::value_type (num, index++));
        }
    }
    for (int &num : arr) {
        num = uSorts[num];
    }
    return arr;
}
