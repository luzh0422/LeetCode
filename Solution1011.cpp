//
// Created by luzh on 2021/4/26.
//

#include "Solution1011.h"

#include <numeric>

int Solution1011::shipWithinDays(vector<int> &weights, int D) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    int mid = (left + right) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        int sum = 0;
        int day = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > mid) {
                day++;
                sum = 0;
            }
            sum += weights[i];
        }
        if (day <= D) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
