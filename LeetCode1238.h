//
// Created by 陆泽辉 on 2023/2/23.
//

#ifndef LEETCODE_LEETCODE1238_H
#define LEETCODE_LEETCODE1238_H

#include <string>
#include <vector>

using namespace std;

class LeetCode1238 {
public:
    vector<int> circularPermutation(int n, int start);

private:
    vector<string> GrayCode(int n);
    vector<int> parse2To10(vector<string>& binarys);
};


#endif //LEETCODE_LEETCODE1238_H
