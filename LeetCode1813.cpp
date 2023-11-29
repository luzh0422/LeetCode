//
// Created by 陆泽辉 on 2023/1/16.
//

#include "LeetCode1813.h"

bool LeetCode1813::areSentencesSimilar(string sentence1, string sentence2) {
    if (sentence1.size() > sentence2.size()) {
        swap(sentence1, sentence2);
    }
    vector<string> arr1 = stringToArray(sentence1);
    vector<string> arr2 = stringToArray(sentence2);
    int n = arr1.size(), m = arr2.size();
    int left = 0, right = 0;
    while (left < n && arr1[left] == arr2[left]) {
        left++;
    }
    while (left + right < n && arr1[n - right - 1] == arr2[m - right - 1]) {
        right++;
    }
    return left + right == n && left + right <= m;
}

vector<string> LeetCode1813::stringToArray(string &sentence) {
    int n = sentence.size();
    vector<string> res;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && sentence[j] != ' ') {
            j++;
        }
        res.push_back(sentence.substr(i, j - i));
        i = j;
    }
    return res;
}
