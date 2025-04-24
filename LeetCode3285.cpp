//
// Created by luzehui on 24-12-19.
//

#include "LeetCode3285.h"

vector<int> LeetCode3285::stableMountains(vector<int> &height, int threshold) {
    vector<int> res{};
    for (int i = 1; i < height.size(); i++) {
        if (height[i - 1] > threshold) {
            res.push_back(i);
        }
    }
    return res;
}
