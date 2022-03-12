//
// Created by luzh on 2021/6/6.
//

#ifndef LEETCODE_SOLUTION474_H
#define LEETCODE_SOLUTION474_H

#include <string>
#include <vector>

using namespace std;

class Solution474 {
public:
    Solution474() {};
    int findMaxForm(vector<string>& strs, int m, int n);

private:
    vector<int> get01Num(string str);
};


#endif //LEETCODE_SOLUTION474_H
