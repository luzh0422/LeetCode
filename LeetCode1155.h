//
// Created by luzehui on 2023/10/23.
//

#ifndef LEETCODE_LEETCODE1155_H
#define LEETCODE_LEETCODE1155_H


class LeetCode1155 {
public:
    int numRollsToTarget(int n, int k, int target);

private:
    int backtrace(int n, int k, int target, int curr);
};


#endif //LEETCODE_LEETCODE1155_H
