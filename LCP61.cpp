//
// Created by luzehui on 2024/6/21.
//

#include "LCP61.h"

struct Trend {
    int A : 3;
};

int LCP61::temperatureTrend(vector<int> &temperatureA, vector<int> &temperatureB) {
    size_t n = temperatureA.size();
    int res = 0, curr = 0;
    for (size_t i = 0; i < n - 1; i++) {
        if (temperatureA[i] < temperatureA[i + 1] && temperatureB[i] < temperatureB[i + 1] || temperatureA[i] > temperatureA[i + 1] && temperatureB[i] > temperatureB[i + 1] || temperatureA[i] == temperatureA[i + 1] && temperatureB[i] == temperatureB[i + 1]) {
            curr++;
        } else {
            res = max(res, curr);
            curr = 0;
        }
    }
    res = max(res, curr);
    return res;
}
