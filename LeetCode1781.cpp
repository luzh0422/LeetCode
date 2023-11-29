//
// Created by 陆泽辉 on 2022/12/12.
//

#include "LeetCode1781.h"

#include <vector>

using namespace std;

int LeetCode1781::beautySum(string s) {
    int n = s.size();
    vector<vector<int>> prefix(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i] - 'a' == j) {
                prefix[i + 1][j] = prefix[i][j] + 1;
            } else {
                prefix[i + 1][j] = prefix[i][j];
            }
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            vector<int> tmp(26, 0);
            int minVal = INT_MAX, maxVal = INT_MIN;
            for (int k = 0; k < 26; k++) {
                tmp[k] = prefix[i + 1][k] - prefix[j][k];
                if (tmp[k] != 0) {
                    minVal = min(tmp[k], minVal);
                }
                if (tmp[k] != 0) {
                    maxVal = max(tmp[k], maxVal);
                }
            }
            if (minVal != INT_MAX && minVal != 0 && maxVal != INT_MIN) {
                res += maxVal - minVal;
            }
        }
    }
    return res;
}
