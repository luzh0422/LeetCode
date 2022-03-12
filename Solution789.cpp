//
// Created by luzh on 2021/8/22.
//

#include "Solution789.h"

bool Solution789::escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    int distance = manhattanDistance({0, 0}, target);
    for (int i = 0; i < ghosts.size(); i++) {
        int currDistance = manhattanDistance(ghosts[i], target);
        if (currDistance <= distance) {
            return false;
        }
    }
    return true;
}

int Solution789::manhattanDistance(vector<int> point1, vector<int> point2) {
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
}
