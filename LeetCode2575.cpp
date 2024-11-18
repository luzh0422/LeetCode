//
// Created by luzehui on 2024/3/7.
//

#include "LeetCode2575.h"

vector<int> LeetCode2575::divisibilityArray(std::string word, int m) {
    int n = word.size();
    vector<int> res(n, 0);
    long long currNum = 0ll;
    for (int i = 0; i < n; i++) {
        currNum *= 10;
        currNum += (word[i] - '0');
        if (currNum % m == 0) {
            res[i] = 1;
        }
        currNum %= m;
    }
    return res;
}
