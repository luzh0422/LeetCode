//
// Created by 陆泽辉 on 2022/11/13.
//

#include "LeetCode791.h"
#include <unordered_map>

string LeetCode791::customSortString(string order, string s) {
    unordered_map<char, int> orders;
    string tmp1 = "", tmp2 = "";
    int index = 0;
    for (auto &ch : order) {
        orders[ch] = index++;
    }
    for (auto &ch : s) {
        if (orders.count(ch)) {
            tmp1 += ch;
        } else {
            tmp2 += ch;
        }
    }
    std::sort(tmp1.begin(), tmp1.end(), [&](char& ch1, char& ch2) -> bool {
            return orders[ch1] <= orders[ch2];
    });

    return tmp1 + tmp2;
}
