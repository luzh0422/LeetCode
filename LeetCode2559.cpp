//
// Created by 陆泽辉 on 2023/6/2.
//

#include "LeetCode2559.h"

vector<int> LeetCode2559::vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
    auto checkFunc = [&](string& word) -> bool {
        char a = word.front();
        char b = word.back();
        if ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') && (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u')) {
            return true;
        }
        return false;
    };
    int n = words.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        string& word = words[i];
        if (checkFunc(word)) {
            prefix[i + 1] = prefix[i] + 1;
        } else {
            prefix[i + 1] = prefix[i];
        }
    }
    int m = queries.size();
    vector<int> res(m, 0);
    for (int i = 0; i < m; i++) {
        int l = queries[i][0];
        int r = queries[i][1] + 1;
        res[i] = prefix[r] - prefix[l];
    }
    return res;
}
