//
// Created by 陆泽辉 on 2022/4/15.
//

#include "LeetCode385.h"


NestedInteger LeetCode385::deserialize(string s) {
    auto res =  deserialize(s, 0);
    return res;
}

NestedInteger LeetCode385::deserialize(string s, int currId) {
    int currNum = 0;
    int n = s.size();
    NestedInteger res;
    for (; currId < n; currId++) {
        if (s[currId] >= '0' && s[currId] <= '9') {
            currNum = currNum * 10 + (s[currId] - '0');
        } else if (s[currId] == ','){
            res.setInteger(currNum);
            currNum = 0;
            res.add(deserialize(s, currId + 2));
            break;
        } else {
            continue;
        }
    }
    if (currNum != 0) {
        res.setInteger(currNum);
    }
    return res;
}
