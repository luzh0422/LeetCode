//
// Created by luzh on 2021/9/10.
//

#include "Solution1894.h"
#include <numeric>

int Solution1894::chalkReplacer(vector<int> &chalk, int k) {
    int sum = this->sum(chalk);
    k = k % sum;
    for (int i = 0; i < chalk.size(); i++) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }
    return -1;
}

int Solution1894::sum(vector<int> &chalk) {
    long long ans = 0;
    for (auto& num: chalk) {
        ans += num;
    }
    return ans;
}
