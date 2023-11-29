//
// Created by 陆泽辉 on 2022/10/15.
//

#include "LeetCode1441.h"

vector<string> LeetCode1441::buildArray(vector<int> &target, int n) {
    int index = 1;
    vector<string> ret;
    for (int i = 0; i < target.size();) {
        if (target[i] == index) {
            ret.push_back("push");
            i++;
        } else {
            ret.push_back("push");
            ret.push_back("pop");
        }
        index++;
    }
    return ret;
}
