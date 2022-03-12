//
// Created by luzh on 2021/12/7.
//

#include "Solution1034.h"

vector<vector<int>> Solution1034::colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
    pair<int, int> curr = {row, col};
    vector<pair<int, int>> positions = {};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    backtrack(grid, vis, positions, {row, col});
    for (int i = 0; i < positions.size(); i++) {
        auto position = positions[i];
        grid[position.first][position.second] = color;
    }
    return grid;
}

void Solution1034::backtrack(vector<vector<int>> &grid, vector<vector<int>> &visit, vector<pair<int, int>>& positions, pair<int, int> curr) {
    const vector<int> steps = {-1, 0, 1, 0, -1};
    int row = grid.size();
    int column = grid[0].size();
    int currRow = curr.first;
    int currColumn = curr.second;
    visit[currRow][currColumn] = 1;
    int count = 0;
    for (int i = 1; i < 5; i++) {
        int stepRow = steps[i - 1];
        int stepColumn = steps[i];
        if (currRow + stepRow >= 0 && currRow + stepRow < row && currColumn + stepColumn >= 0 && currColumn + stepColumn < column && grid[currRow][currColumn] == grid[currRow + stepRow][currColumn + stepColumn]){
            if (visit[currRow + stepRow][currColumn + stepColumn] == 0) {
                backtrack(grid, visit, positions, {currRow + stepRow, currColumn + stepColumn});
            }
            count++;
        }
    }
    if (count != 4) {
        positions.push_back(curr);
    }
    return;
}
