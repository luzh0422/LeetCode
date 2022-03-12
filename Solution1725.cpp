//
// Created by luzh on 2022/2/4.
//

#include "Solution1725.h"

int Solution1725::countGoodRectangles(vector<vector<int>> &rectangles) {
    int l0 = rectangles[0][0];
    int w0 = rectangles[0][1];
    int maxLength = min(l0, w0);
    int ans = 1;
    int n = rectangles.size();
    for (int i = 1; i < n; i++) {
        l0 = rectangles[i][0];
        w0 = rectangles[i][1];
        int curr = min(l0, w0);
        if (curr > maxLength) {
            ans = 1;
            maxLength = curr;
        } else if (curr == maxLength) {
            ans++;
        }
    }
    return ans;
}
