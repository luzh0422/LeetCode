//
// Created by luzh on 2022/2/8.
//

#include "Solution1001.h"

#include <unordered_map>

using namespace std;

vector<int> Solution1001::gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
    vector<pair<int, int>> dirs = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    unordered_map<int, int> row, col, diagonal, annoyingDiagonal, lights;
    int lampsN = lamps.size();
    for (int i = 0; i < lampsN; i++) {
        int x = lamps[i][0], y = lamps[i][1];
        int index = x * n + y;
        if (lights.count(index)) {
            continue;
        }
        if (row.count(x)) {
            row[x]++;
        } else {
            row.insert(unordered_map<int, int>::value_type(x, 1));
        }
        if (col.count(y)) {
            col[y]++;
        } else {
            col.insert(unordered_map<int, int>::value_type(y, 1));
        }
        if (diagonal.count(x + y)) {
            diagonal[x + y]++;
        } else {
            diagonal.insert(unordered_map<int, int>::value_type(x + y, 1));
        }
        if (annoyingDiagonal.count(x - y)) {
            annoyingDiagonal[x - y]++;
        } else {
            annoyingDiagonal.insert(unordered_map<int, int>::value_type(x - y, 1));
        }
        lights.insert(unordered_map<int, int>::value_type(index, 1));
    }
    int queriesN = queries.size();
    vector<int> ans(queriesN, 0);
    for (int i = 0; i < queriesN; i++) {
        int x = queries[i][0];
        int y = queries[i][1];
        if (row.count(x) && row[x] > 0) {
            ans[i] = 1;
        } else if (col.count(y) && col[y] > 0) {
            ans[i] = 1;
        } else if (diagonal.count(x + y) && diagonal[x + y] > 0) {
            ans[i] = 1;
        } else if (annoyingDiagonal.count(x - y) && annoyingDiagonal[x - y] > 0) {
            ans[i] = 1;
        }
        for (int i = 0; i < 9; i++) {
            int tempX = x + dirs[i].first;
            int tempY = y + dirs[i].second;
            int tempIndex = tempX * n + tempY;
            if (lights.count(tempIndex)) {
                row[tempX]--;
                col[tempY]--;
                diagonal[tempX + tempY]--;
                annoyingDiagonal[tempX - tempY]--;
                lights.erase(tempIndex);
            }
        }
    }
    return ans;
}
