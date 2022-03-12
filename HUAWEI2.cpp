//
// Created by luzh on 2021/10/23.
//

#include "HUAWEI2.h"

#include <unordered_map>
#include <vector>

string HUAWEI2::sortString(string s) {
    unordered_map<char, int> uM;
    for (auto c : s) {
        if (uM.count(c)) {
            uM[c]++;
        } else {
            uM[c] = 1;
        }
    }
    vector<pair<char, int>> arr;
    for (auto value : uM) {
        arr.push_back(value);
    }
    sort(arr.begin(), arr.end(), [](const pair<char, int>& value1, const pair<char, int>& value2) -> bool {
        if (value1.second > value2.second) {
            return true;
        } else if (value1.second == value2.second) {
            return value1.first < value2.first;
        } else {
            return false;
        }
    });
    string ans = "";
    for (auto value : arr) {
        for (int i = 0; i < value.second; i++) {
            ans += value.first;
        }
    }
    return ans;
}
