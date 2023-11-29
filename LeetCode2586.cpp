//
// Created by luzehui on 2023/11/6.
//

#include "LeetCode2586.h"

int LeetCode2586::vowelStrings(vector<std::string> &words, int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) {
        string word = words[i];
        char first = word.front();
        char last = word.back();
        if ((first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') && (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u')) {
            ans++;
        }
    }
    return ans;
}
