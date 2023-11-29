//
// Created by luzehui on 2023/11/5.
//

#include "LeetCode318.h"

int LeetCode318::maxProduct(vector<std::string> &words) {
    int n = words.size();
    vector<int> wordsInt(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string word = words[i];
        int wordInt = sToI(word);
        wordsInt[i] = wordInt;
        for (int j = 0; j < i; j++) {
            if ((wordsInt[j] & wordInt) == 0) {
                ans = max((int)words[j].size() * (int)words[i].size(), ans);
            }
        }
    }
    return ans;
}

int LeetCode318::sToI(std::string &word) {
    int n = word.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char c = word[i];
        ans |= (1 << (c - 'a'));
    }
    return ans;
}
