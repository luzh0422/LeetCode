//
// Created by luzh on 2022/2/10.
//

#include "Solution1447.h"

vector<string> Solution1447::simplifiedFractions(int n) {
    vector<string> ans = {};
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (isSimplifiedFraction(j, i)) {
                ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
    }
    return ans;
}

bool Solution1447::isSimplifiedFraction(int a, int b) {
    while (b != 0) {
        if (b % a == 0) {
            b = 0;
        } else {
            int temp = b % a;
            b = a;
            a = temp;
        }
    }
    if (a == 1) {
        return true;
    } else {
        return false;
    }
}
