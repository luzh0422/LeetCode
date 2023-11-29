//
// Created by luzh on 2022/1/15.
//

#include "Solution378.h"
#include <queue>

int Solution378::kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    std::function<bool(int, int)> cmp = [&matrix, n](int num1, int num2) -> bool {
        int row1 = num1 / n;
        int column1 = num1 % n;
        int row2 = num2 / n;
        int column2 = num2 % n;
        return matrix[row1][column1] > matrix[row2][column2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        pq.push(i * n);
    }
    int row, column;
    while (k > 0 && !pq.empty()) {
        int index = pq.top();
        pq.pop();
        row = index / n;
        column = index % n;
        if (column < n - 1) {
            pq.emplace(row * n + column + 1);
        }
        k--;
    }
    return matrix[row][column];
}
