//
// Created by luzehui on 2023/10/24.
//

#ifndef LEETCODE_LEETCODE2698_H
#define LEETCODE_LEETCODE2698_H


class LeetCode2698 {
public:
    int punishmentNumber(int n);

private:
    bool backtrace(int n, int curr, int target);
};


#endif //LEETCODE_LEETCODE2698_H
