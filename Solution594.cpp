//
// Created by luzh on 2021/11/20.
//

#include "Solution594.h"
#include <unordered_map>

int Solution594::findLHS(vector<int> &nums) {
    unordered_map<int, int> uM;
    int ans = 0;
    for (int &num : nums) {
        if (uM.count(num)) {
            uM[num]++;
        } else {
            uM[num] = 1;
        }
        if (uM.count(num - 1)) {
            ans = max(ans, uM[num] + uM[num - 1]);
        }
        if (uM.count(num + 1)) {
            ans = max(ans, uM[num] + uM[num + 1]);
        }
    }
    return ans;
}
