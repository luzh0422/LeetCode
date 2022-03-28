//
// Created by luzh on 2022/3/14.
//

#include "LeetCode599.h"

#include <unordered_map>

vector<string> LeetCode599::findRestaurant(vector<string> &list1, vector<string> &list2) {
    int n1 = list1.size(), n2 = list2.size();
    unordered_map<string, pair<int, int>> uM;
    vector<string> ret;
    for (int i = 0; i < n1; i++) {
        if (!uM.count(list1[i])) {
            uM.insert(unordered_map<string, pair<int, int>>::value_type (list1[i], {i, 1}));
        }
    }
    for (int i = 0; i < n2; i++) {
        if (uM.count(list2[i])) {
            uM[list2[i]].first += i;
            uM[list2[i]].second += 1;
        }
    }
    int minVal = 0x3f3f3f3f;
    for (auto it = uM.begin(); it != uM.end(); it++) {
        if (it->second.second > 1) {
            if (it->second.first < minVal) {
                ret.clear();
                ret.push_back(it->first);
                minVal = it->second.second;
            } else if (it->second.first == minVal) {
                ret.push_back(it->first);
            }
        }
    }

    return ret;
}
