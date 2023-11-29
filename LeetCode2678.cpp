//
// Created by luzehui on 2023/10/22.
//

#include "LeetCode2678.h"

int LeetCode2678::countSeniors(vector<std::string> &details) {
    int ans = 0;
    for (auto detail : details) {
        string age = detail.substr(11, 2);
        int ageI = stoi(age);
        if (ageI > 60) {
           ans++;
        }
    }
    return ans;
}
