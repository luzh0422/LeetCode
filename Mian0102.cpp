//
// Created by 陆泽辉 on 2022/9/27.
//

#include "Mian0102.h"

#include <map>

bool Mian0102::CheckPermutation(string s1, string s2) {
    map<char, int> m1;
    map<char, int> m2;
    for (auto& c : s1) {
        if (m1.count(c)) {
            m1[c]++;
        } else {
            m1.insert(map<char, int>::value_type(c, 1));
        }
    }
    for (auto& c : s2) {
        if (m2.count(c)) {
            m2[c]++;
        } else {
            m2.insert(map<char, int>::value_type(c, 1));
        }
    }
    if (m1.size() != m2.size()) {
        return false;
    }
    for (auto iter1 = m1.begin(), iter2 = m2.begin(); iter1 != m1.end(), iter2 != m2.end(); iter1++, iter2++) {
        if (iter1->second != iter2->second || iter1->first != iter2->first) {
            return false;
        }
    }
    return true;
}
