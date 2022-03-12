//
// Created by luzh on 2021/12/20.
//

#include "Solution475.h"

int Solution475::findRadius(vector<int> &houses, vector<int> &heaters) {
    int ans = 0;
    int n = houses.size();
    std::sort(heaters.begin(), heaters.end());
    for (int i = 0; i < n; i++) {
        int house = houses[i];
        auto it = lower_bound(heaters.begin(), heaters.end(), house);
        if (it == heaters.begin()) {
            ans = max(ans, abs(*it - house));
        } else if (it == heaters.end()) {
            ans = max(ans, abs(*(--it) - house));
        } else {
            ans = max(ans, min(abs(*it - house), abs(*(--it) - house)));
        }
    }
    return ans;
}
