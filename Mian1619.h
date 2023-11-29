//
// Created by 陆泽辉 on 2023/6/22.
//

#ifndef LEETCODE_MIAN1619_H
#define LEETCODE_MIAN1619_H

#include <vector>

using namespace std;

class Mian1619 {
public:
    vector<int> pondSizes(vector<vector<int>>& land);

private:
    int bfs(vector<vector<int>>& land, vector<vector<int>> &visits, int currRow, int currCol);
};


#endif //LEETCODE_MIAN1619_H
