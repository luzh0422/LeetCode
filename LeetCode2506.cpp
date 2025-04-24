//
// Created by luzehui on 25-2-23.
//

#include "LeetCode2506.h"

int LeetCode2506::similarPairs(vector<std::string> &words) {
    int n = words.size();
    vector<int> wordToNum;
    for (auto& word : words) {
        int num = 0;
        for (char i : word) {
            num |= (1 << (i - 'a'));
        }
        wordToNum.push_back(num);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wordToNum[i] == wordToNum[j]) {
                res++;
            }
        }
    }
    return res;
}
