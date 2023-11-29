//
// Created by 陆泽辉 on 2023/6/30.
//

#include "LeetCode2490.h"

#include <vector>

bool LeetCode2490::isCircularSentence(string sentence) {
    vector<string> temp{};
    int n = sentence.size();
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && sentence[j] != ' ') {
            j++;
        }
        string s = sentence.substr(i, j - i);
        temp.push_back(s);
        i = j + 1;
    }
    int m = temp.size();
    if (temp[0].front() != temp[m - 1].back()) {
        return false;
    }
    for (int i = 0; i < m - 1; i++) {
        if (temp[i].back() != temp[i + 1].front()) {
            return false;
        }
    }
    return true;
}
