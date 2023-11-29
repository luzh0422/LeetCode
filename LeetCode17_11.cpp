//
// Created by 陆泽辉 on 2022/5/27.
//

#include "LeetCode17_11.h"
#include <unordered_map>

int LeetCode17_11::findClosest(vector<string> &words, string word1, string word2) {
    unordered_map<string, vector<int>> uM;
    int n = words.size();
    for (int i = 0; i < n; i++) {
        string word = words[i];
        if (uM.count(word)) {
            uM[word].emplace_back(i);
        } else {
            uM.insert(unordered_map<string, vector<int>>::value_type(word, {i}));
        }
    }
    auto arr1 = uM[word1], arr2 = uM[word2];
    int n1 = arr1.size(), n2 = arr2.size();
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            ret = min(abs(arr1[i] - arr2[j]), ret);
        }
    }
    return ret;
}
