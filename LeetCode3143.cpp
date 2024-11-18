//
// Created by luzehui on 2024/8/3.
//

#include "LeetCode3143.h"

int LeetCode3143::maxPointsInsideSquare(vector<vector<int>> &points, std::string s) {
    int min2 = 1e9 + 1;
    size_t n = points.size();
    vector<int> min1(26, 1e9 + 1);
    for (int i = 0; i < n; i++) {
        int x = abs(points[i][0]), y = abs(points[i][1]), tag = s[i] - 'a';
        int d = max(x, y);
        if (d < min1[tag]) {
            min2 = min(min2, min1[tag]);
            min1[tag] = d;
        } else {
            min2 = min(min2, d);
        }
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (min1[i] < min2) {
            res++;
        }
    }
    return res;
}
