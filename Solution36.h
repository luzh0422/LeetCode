//
// Created by luzh on 2021/9/17.
//

#ifndef LEETCODE_SOLUTION36_H
#define LEETCODE_SOLUTION36_H

#include <vector>

using namespace std;

class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board);
    bool isValidSudoku(vector<vector<char>>& board, int row, int column);

private:
    int getNumByChar(char c);
};


#endif //LEETCODE_SOLUTION36_H
