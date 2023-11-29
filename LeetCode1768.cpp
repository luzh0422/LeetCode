//
// Created by 陆泽辉 on 2022/10/23.
//

#include "LeetCode1768.h"

string LeetCode1768::mergeAlternately(string word1, string word2) {
    string ret = "";
    int index1 = 0, index2 = 0, n1 = word1.size(), n2 = word2.size();
    while (index1 < n1 && index2 < n2) {
        ret += word1[index1++];
        ret += word2[index2++];
    }
    while (index1 < n1) {
        ret += word1[index1++];
    }
    while (index2 < n2) {
        ret += word2[index2++];
    }
    return ret;
}
