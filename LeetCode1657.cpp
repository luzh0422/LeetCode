//
// Created by luzehui on 2023/11/30.
//

#include "LeetCode1657.h"

bool LeetCode1657::closeStrings(std::string word1, std::string word2) {
    if (word1.size() != word2.size()) {
        return false;
    }
    vector<int> char1(26, 0), char2(26, 0);
    int n = word1.size();
    for (int i = 0; i < n; i++) {
        char1[word1[i] - 'a']++;
        char2[word2[i] - 'a']++;
    }
    vector<int> arr1, arr2;
    for (int i = 0; i < 26; i++) {
        if (char1[i] != 0 && char2[i] == 0 || char1[i] == 0 && char2[i] != 0) {
            return false;
        }
        arr1.push_back(char1[i]);
        arr2.push_back(char2[i]);
    }
    std::sort(char1.begin(), char1.end());
    std::sort(char2.begin(), char2.end());
    n = char1.size();
    for (int i = 0; i < n; i++) {
        if (char1[i] != char2[i]) {
            return false;
        }
    }
    return true;
}
