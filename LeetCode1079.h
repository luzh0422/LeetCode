//
// Created by 陆泽辉 on 2023/5/19.
//

#ifndef LEETCODE_LEETCODE1079_H
#define LEETCODE_LEETCODE1079_H

#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class LeetCode1079 {
public:
    int numTilePossibilities(string tiles);

private:
    int dfs(unordered_map<char, int>& count, set<char>& tile);
};


#endif //LEETCODE_LEETCODE1079_H
