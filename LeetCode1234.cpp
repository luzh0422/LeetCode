//
// Created by 陆泽辉 on 2023/2/13.
//

#include "LeetCode1234.h"
#include <vector>

int LeetCode1234::balancedString(string s) {
    int n = s.size();
    vector<vector<int>> accounts(n + 1, vector<int>(4, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            accounts[i + 1][j] = accounts[i][j];
        }
        switch(s[i]) {
            case 'Q':
                accounts[i + 1][0]++;
                break;
            case 'W':
                accounts[i + 1][1]++;
                break;
            case 'E':
                accounts[i + 1][2]++;
                break;
            case 'R':
                accounts[i + 1][3]++;
                break;
        }
    }
    int res = INT_MAX, target = n / 4;
    int i = 0, j = 0;
    for (; i <= n; i++) {
        for (; j <= n; j++) {
            bool tag = true;
            for (int k = 0; k < 4; k++) {
                if (accounts[i][k] - accounts[0][k] + accounts[n][k] - accounts[j][k] > target) {
                    tag = false;
                }
            }
            if (tag) {
                res = min(res, j - i);
                break;
            }

        }
    }
    return res;
}
