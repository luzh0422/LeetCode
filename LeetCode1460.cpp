//
// Created by 陆泽辉 on 2022/8/24.
//

#include "LeetCode1460.h"
#include <unordered_map>

bool LeetCode1460::canBeEqual(vector<int> &target, vector<int> &arr) {
    unordered_map<int, int> targetUM;
    for (int num : target) {
        if (targetUM.count(num)) {
            targetUM[num]++;
        } else {
            targetUM.insert(unordered_map<int, int>::value_type (num, 1));
        }
    }
    for (int num : arr) {
        if (targetUM.count(num)) {
            targetUM[num]--;
            if (targetUM[num] == 0) {
                targetUM.erase(num);
            }
        } else {
            return false;
        }
    }
    if (targetUM.size() != 0) {
        return false;
    }
    return true;
}
