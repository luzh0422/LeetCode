//
// Created by luzh on 2022/1/30.
//

#include "Solution884.h"

#include <unordered_map>

vector<string> Solution884::uncommonFromSentences(string s1, string s2) {
    int l1 = s1.size(), l2 = s2.size();
    int start1 = 0, length1 = 0, start2 = 0, length2 = 0;
    unordered_map<string, int> uM;
    for (int i = 0; i < l1 || i < l2; i++) {
        if (i < l1) {
            if (s1[i] == ' ') {
                string curr = s1.substr(start1, length1);
                if (uM.count(curr)) {
                    uM[curr]++;
                } else {
                    uM.insert(unordered_map<string, int>::value_type(curr, 1));
                }
                start1 = i + 1;
                length1 = 0;
            } else {
                length1++;
            }
        }
        if (i < l2) {
            if (s2[i] == ' ') {
                string curr = s2.substr(start2, length2);
                if (uM.count(curr)) {
                    uM[curr]++;
                } else {
                    uM.insert(unordered_map<string, int>::value_type(curr, 1));
                }
                start2 = i + 1;
                length2 = 0;
            } else {
                length2++;
            }
        }
    }
    if (length1 != 0) {
        string curr = s1.substr(start1, length1);
        if (uM.count(curr)) {
            uM[curr]++;
        } else {
            uM.insert(unordered_map<string, int>::value_type(curr, 1));
        }
    }
    if (length2 != 0) {
        string curr = s2.substr(start2, length2);
        if (uM.count(curr)) {
            uM[curr]++;
        } else {
            uM.insert(unordered_map<string, int>::value_type(curr, 1));
        }
    }
    vector<string> ans = {};
    for (auto [key, value]: uM) {
        if (value == 1) {
            ans.push_back(key);
        }
    }
    return ans;
}
