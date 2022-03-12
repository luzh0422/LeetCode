//
// Created by luzh on 2021/6/6.
//

#include "Solution474.h"

int Solution474::findMaxForm(vector<string> &strs, int m, int n) {
    int size = strs.size();
    vector<vector<vector<int>>> dp(size, vector<vector<int>>(m + 1, vector<int>(n + 1)));
    int ans = 0;
    for (int i = 0; i < strs.size(); i++) {
        string str = strs[i];
        vector<int> zeroOneNum = get01Num(str);
        int zero = zeroOneNum[0];
        int one = zeroOneNum[1];

    }
    return ans;
}

vector<int> Solution474::get01Num(string str) {
    vector<int> ans = {};
    int zero = 0, one = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            zero += 1;
        } else {
            one += 1;
        }
    }
    ans.push_back(zero);
    ans.push_back(one);
    return ans;
}
