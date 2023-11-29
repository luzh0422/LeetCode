//
// Created by 陆泽辉 on 2023/5/25.
//

#include "LeetCode2451.h"

string LeetCode2451::oddString(vector<string> &words) {
    int n = words[0].size();
    int m = words.size();
    string word0 = words[0];
    vector<int> target(n - 1);
    for (int i = 1; i < n; i++) {
        target[i - 1] = word0[i] - word0[i - 1];
    }
    string res = "-1";
    int count = 0;
    for (int i = 1; i < m; i++) {
        string word = words[i];
        for (int j = 1; j < n; j++) {
            if (word[j] - word[j - 1] != target[j - 1]) {
                res = word;
                count++;
                break;
            }
        }
    }
    if (count > 1) {
        return word0;
    }
    return res;
}
