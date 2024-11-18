//
// Created by luzehui on 2024/11/12.
//

#include "LeetCode3258.h"
#include <vector>

int LeetCode3258::countKConstraintSubstrings(std::string s, int k) {
    int n = s.size();
    vector<int> zeroCount(n + 1, 0);
    vector<int> oneCount(n + 1, 0);
    for (int i = 0; i < n; i++) {
        zeroCount[i + 1] = zeroCount[i];
        oneCount[i + 1] = oneCount[i];
        if (s[i] == '0') {
            zeroCount[i + 1]++;
        } else {
            oneCount[i + 1]++;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (zeroCount[i + 1] - zeroCount[j] < k + 1 || oneCount[i + 1] - oneCount[j] < k + 1) {
                res++;
            }
        }
    }
    return res;
}
