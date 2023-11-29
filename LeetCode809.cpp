//
// Created by 陆泽辉 on 2022/11/25.
//

#include "LeetCode809.h"

int LeetCode809::expressiveWords(string s, vector<string> &words) {
    int res = 0;
    for (auto& word : words) {
        if (expressiveWords(s, word)) {
            res++;
        }
    }
    return res;
}

int LeetCode809::expressiveWords(string &s, string &word) {
    int i = 0, j = 0, sC = 0, wC = 0;
    int sN = s.size(), wordN = word.size();
    while (i < sN && j < wordN) {
        sC = 1, wC = 1;
        while (i < sN - 1 && s[i] == s[i + 1]) {
            sC++;
            i++;
        }
        while (j < wordN - 1 && word[j] == word[j + 1]) {
            wC++;
            j++;
        }
        if (sC > wC && sC < 3 || wC > sC) {
            return false;
        }
        if (s[i] != word[j]) {
            return false;
        }
        i++;
        j++;
    }
    return i == s.size() && j == word.size();
}
