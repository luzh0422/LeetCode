//
// Created by luzehui on 2024/11/21.
//

#include "LeetCode3248.h"
#include <unordered_map>

int LeetCode3248::finalPositionOfSnake(int n, vector<std::string> &commands) {
    int res = 0;
    unordered_map<string, int> cases = {{"UP", 0}, {"DOWN", 1}, {"RIGHT", 2}, {"LEFT", 3}};
    for (auto &command : commands) {
        switch (cases[command]) {
            case 0:
                res -= n;
                break;
            case 1:
                res += n;
                break;
            case 2:
                res += 1;
                break;
            case 3:
                res -= 1;
                break;
        }
    }
    return res;
}
