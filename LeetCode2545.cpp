//
// Created by luzehui on 24-12-21.
//

#include "LeetCode2545.h"

vector<vector<int>> LeetCode2545::sortTheStudents(vector<vector<int>> &score, int k) {
    std::sort(score.begin(), score.end(), [&](vector<int>& arr1, vector<int>& arr2) -> bool {
        return arr1[k] > arr2[k];
    });
    return score;
}
