//
// Created by 陆泽辉 on 2023/9/14.
//

#include "LeetCode1222.h"
#include <set>

vector<vector<int>> LeetCode1222::queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
    set<vector<int>> s;
    vector<vector<int>> res;
    for (auto& queen : queens) {
        s.insert(queen);
    }
    vector<vector<int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < 8; i++) {
        int kingRow = king[0], kingCol = king[1];
        auto& direction = directions[i];
        kingRow += direction[0];
        kingCol += direction[1];
        while (kingRow >= 0 && kingRow < 8 && kingCol >= 0 && kingCol < 8) {
            if (s.count({kingRow, kingCol})) {
                res.push_back({kingRow, kingCol});
                break;
            }
            kingRow += direction[0];
            kingCol += direction[1];
        }
    }
    return res;
}
