//
// Created by 陆泽辉 on 2022/5/3.
//

#include "LeetCode937.h"

vector<string> LeetCode937::reorderLogFiles(vector<string> &logs) {
    vector<string> chars, nums;
    int n = logs.size();
    for (int i = 0; i < n; i++) {
        string log = logs[i];
        if (log.back() >= '0' && log.back() <= '9') {
            nums.push_back(log);
        } else {
            chars.push_back(log);
        }
    }
    auto cmp = [](const string& s1, const string& s2) -> bool {
        string tag1, tag2;
        int index1 = 0, index2 = 0, n1 = s1.size(), n2 = s2.size();
        for (int i = 0; i < n1; i++) {
            if (s1[i] == ' ') {
                tag1 = s1.substr(index1, i - index1);
                index1 = i + 1;
                break;
            }
        }
        for (int i = 0; i < n2; i++) {
            if (s2[i] == ' ') {
                tag2 = s2.substr(index2, i - index2);
                index2 = i + 1;
                break;
            }
        }
        int i = index1, j = index2;
        for (; i < n1 && j < n2; i++, j++) {
            while (s1[i] == ' ') {
                i++;
            }
            while (s2[j] == ' ') {
                j++;
            }
            if (s1[i] > s2[j]) {
                return false;
            } else if (s1[i] < s2[j]) {
                return true;
            }

        }
        if (i == n1 && j != n2) {
            return true;
        } else if (i != n1 && j == n2) {
            return false;
        }
        return tag1 <= tag2;
    };
    sort(chars.begin(), chars.end(), cmp);
//    chars.emplace_back(nums.begin(), nums.end());
    chars.insert(chars.end(), nums.begin(), nums.end());
    return chars;
}
