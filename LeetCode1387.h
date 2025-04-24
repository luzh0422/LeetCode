//
// Created by luzehui on 24-12-22.
//

#ifndef LEETCODE_LEETCODE1387_H
#define LEETCODE_LEETCODE1387_H

#include <vector>
#include <unordered_map>

using namespace std;

class LeetCode1387 {
public:
    int getKth(int lo, int hi, int k);

private:
    int getWeight(int value);
    unordered_map<int, int> uM;
};


#endif //LEETCODE_LEETCODE1387_H
