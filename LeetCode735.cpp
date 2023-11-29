//
// Created by 陆泽辉 on 2022/7/13.
//

#include "LeetCode735.h"

vector<int> LeetCode735::asteroidCollision(vector<int> &asteroids) {
    int n = asteroids.size();
    vector<int> ret = {};
    ret.push_back(asteroids[0]);
    for (int i = 1; i < n; i++) {
        while (ret.size() > 0 && ret.back() > 0 && asteroids[i] < 0 && abs(ret.back()) < abs(asteroids[i])) {
            ret.pop_back();
        }
        if (ret.size() == 0 || ret.back() < 0 || asteroids[i] > 0) {
            ret.push_back(asteroids[i]);
        } else if (abs(ret.back()) == abs(asteroids[i])) {
            if (ret.back() > 0 && asteroids[i] < 0) {
                ret.pop_back();
            } else {
                ret.push_back(asteroids[i]);
            }
        }
    }
    return ret;
}
