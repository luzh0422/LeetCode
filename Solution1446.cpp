//
// Created by luzh on 2021/12/1.
//

#include "Solution1446.h"
#include <vector>

int Solution1446::maxPower(string s) {
    int n = s.size();
    if (n == 0) {
        return 0;
    }
    int last = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            last++;
            ans = max(ans, last);
        } else {
            last = 1;
        }
    }
    return ans;
}
