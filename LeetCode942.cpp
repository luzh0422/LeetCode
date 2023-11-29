//
// Created by 陆泽辉 on 2022/5/9.
//

#include "LeetCode942.h"

vector<int> LeetCode942::diStringMatch(string s) {
    int minNum = 0, maxNum = s.size(), n = s.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            ans.push_back(minNum);
            minNum++;
        } else {
            ans.push_back(maxNum);
            maxNum--;
        }
    }
    ans.push_back(minNum);
    return ans;
}
