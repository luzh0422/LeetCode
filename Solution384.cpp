//
// Created by luzh on 2021/11/22.
//

#include "Solution384.h"

Solution384::Solution384(vector<int> &nums) {
    int n = nums.size();
    this->origin.resize(n);
    copy(nums.begin(), nums.end(), this->origin.begin());
}

vector<int> Solution384::reset() {
    return this->origin;
}

vector<int> Solution384::shuffle() {
    vector<int> list(this->origin.begin(), this->origin.end());
    vector<int> ans = {};
    while (!list.empty()) {
        int index = random() % list.size();
        ans.push_back(list[index]);
        list.erase(list.begin() + index);
    }
    return ans;
}
