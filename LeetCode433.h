//
// Created by 陆泽辉 on 2022/5/7.
//

#ifndef LEETCODE_LEETCODE433_H
#define LEETCODE_LEETCODE433_H

#include <string>
#include <vector>

using namespace std;

class LeetCode433 {
public:
    int minMutation(string start, string end, vector<string>& bank);

private:
    int mutation(string s1, string s2);
};


#endif //LEETCODE_LEETCODE433_H
