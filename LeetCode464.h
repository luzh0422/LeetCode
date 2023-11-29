//
// Created by 陆泽辉 on 2022/5/22.
//

#ifndef LEETCODE_LEETCODE464_H
#define LEETCODE_LEETCODE464_H

#include <unordered_map>

using namespace std;

class LeetCode464 {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal);

private:
    bool canIWin(int maxChoosableInteger, int desiredTotal, int used, unordered_map<int, bool> &records);
};


#endif //LEETCODE_LEETCODE464_H
