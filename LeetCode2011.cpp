//
// Created by 陆泽辉 on 2022/12/23.
//

#include "LeetCode2011.h"

int LeetCode2011::finalValueAfterOperations(vector<string> &operations) {
    int ans = 0;
    for (string& operation : operations) {
        if (operation.front() == '+' || operation.back() == '+') {
            ans++;
        } else {
            ans--;
        }
    }
    return ans;
}
