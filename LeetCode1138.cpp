//
// Created by 陆泽辉 on 2023/2/12.
//

#include "LeetCode1138.h"
#include <queue>

string LeetCode1138::alphabetBoardPath(string target) {
    int n = target.size();
    pair<int, int> curr = {0, 0};
    string res = "";
    for (int i = 0; i < n; i++) {
        string path = "";
        curr = BFS(target[i], curr, path);
        res += path;
    }
    return res;
}

pair<int, int> LeetCode1138::BFS(char target, pair<int, int> &curr, string& path) {
    vector<vector<char>> codes = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'j'},
        {'k', 'l', 'm', 'n', 'o'},
        {'p', 'q', 'r', 's', 't'},
        {'u', 'v', 'w', 'x', 'y'},
        {'z'}
    };
    vector<vector<int>> visits = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1}
    };
    queue<pair<pair<int, int>, string>> q;
    q.push({curr, ""});
    visits[curr.first][curr.second] = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        auto tempPath = node.second;
        auto currPos = node.first;
        auto x = currPos.first;
        auto y = currPos.second;
        if (codes[x][y] == target) {
            path = tempPath + "!";
            return {x, y};
        }
        if (x > 0 && visits[x - 1][y] == 1) {
            visits[x - 1][y] = 0;
            q.push({{x - 1, y}, tempPath + "U"});
        }
        if ((x < 4 || x == 4 && y == 0) && visits[x + 1][y] == 1) {
            visits[x + 1][y] = 0;
            q.push({{x + 1, y}, tempPath + "D"});
        }
        if (y > 0 && visits[x][y - 1] == 1) {
            visits[x][y - 1] = 0;
            q.push({{x, y - 1}, tempPath + "L"});
        }
        if (x < 5 && y < 4 && visits[x][y + 1] == 1) {
            visits[x][y + 1] = 0;
            q.push({{x, y + 1}, tempPath + "R"});
        }
    }
    return {0, 0};
}
