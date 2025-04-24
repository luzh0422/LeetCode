//
// Created by luzehui on 24-12-22.
//

#include "LeetCode1387.h"

int LeetCode1387::getWeight(int value) {
    if (uM.count(value)) {
        return uM[value];
    }
    if (value == 1) {
        return 0;
    }
    if ((value & 1) == 0) {
        return getWeight(value / 2) + 1;
    } else {
        return getWeight(value * 3 + 1) + 1;
    }
}

int LeetCode1387::getKth(int lo, int hi, int k) {
    vector<int> arr{};
    for (int i = lo; i <= hi; i++) {
        arr.push_back(i);
    }
    std::sort(arr.begin(), arr.end(), [&](int num1, int num2) -> bool {
        int weight1 = getWeight(num1);
        int weight2 = getWeight(num2);
        if (weight1 < weight2) {
            return true;
        } else if (weight1 == weight2) {
            return num1 < num2;
        }
        return false;
    });
    return arr[k - 1];
}
