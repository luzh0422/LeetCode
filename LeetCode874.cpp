//
// Created by 陆泽辉 on 2023/7/19.
//

#include "LeetCode874.h"
#include <unordered_set>
#include <set>

int LeetCode874::robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int currX = 0, currY = 0;
    int stepX = 0, stepY = 1;
    set<pair<int, int>> obstaclesHash;
    int res = 0;
    for (int i = 0; i < obstacles.size(); i++) {
        obstaclesHash.insert({obstacles[i][0], obstacles[i][1]});
    }
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == -1) {
            if (stepX == 0 && stepY == 1) {
                stepX = 1;
                stepY = 0;
            } else if (stepX == 1 && stepY == 0) {
                stepX = 0;
                stepY = -1;
            } else if (stepX == 0 && stepY == -1) {
                stepX = -1;
                stepY = 0;
            } else {
                stepX = 0;
                stepY = 1;
            }
        } else if (commands[i] == -2) {
            if (stepX == 0 && stepY == 1) {
                stepX = -1;
                stepY = 0;
            } else if (stepX == -1 && stepY == 0) {
                stepX = 0;
                stepY = -1;
            } else if (stepX == 0 && stepY == -1) {
                stepX = 1;
                stepY = 0;
            } else {
                stepX = 0;
                stepY = 1;
            }
        } else {
            int command = commands[i];
            for (int i = 0; i < command; i++) {
                int nextX = currX + stepX;
                int nextY = currY + stepY;
                if (obstaclesHash.count({nextX, nextY})) {
                    break;
                }
                currX = nextX;
                currY = nextY;
                res = max(res, currX * currX + currY * currY);
            }
        }
    }
    return res;
}
