//
// Created by 陆泽辉 on 2023/2/12.
//

#ifndef LEETCODE_LEETCODE1138_H
#define LEETCODE_LEETCODE1138_H

#include <string>

using namespace std;

class LeetCode1138 {
public:
    string alphabetBoardPath(string target);

private:
    pair<int, int> BFS(char target, pair<int, int>& curr, string& path);
};


#endif //LEETCODE_LEETCODE1138_H
