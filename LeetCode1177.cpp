//
// Created by 陆泽辉 on 2023/6/15.
//

#include "LeetCode1177.h"

vector<bool> LeetCode1177::canMakePaliQueries(string s, vector<vector<int>> &queries) {
    int n = s.size();
    vector<vector<int>> prefix(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        char c = s[i];
        for (int j = 0; j < 26; j++) {
            prefix[i + 1][j] = prefix[i][j];
        }
        prefix[i + 1][c - 'a']++;
    }
    n = queries.size();
    vector<bool> res(n);
    for (int i = 0; i < n; i++) {
        int left = queries[i][0];
        int right = queries[i][1] + 1;
        int count = queries[i][2];
        int temp = 0;
        for (int i = 0; i < 26; i++) {
            if ((prefix[right][i] - prefix[left][i]) % 2 == 1) {
                temp++;
            }
        }
        if (temp / 2 <= count) {
            res[i] = true;
        } else {
            res[i] = false;
        }
    }
    return res;
}
