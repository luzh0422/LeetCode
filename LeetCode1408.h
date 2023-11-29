//
// Created by 陆泽辉 on 2022/8/6.
//

#ifndef LEETCODE_LEETCODE1408_H
#define LEETCODE_LEETCODE1408_H

#include <string>
#include <vector>

using namespace std;

class LeetCode1408 {
public:
    vector<string> stringMatching(vector<string>& words);

private:
    int KMP(string& s1, string& s2, vector<int>& steps);
    void makeNext(string& p, vector<int>& next);
};


#endif //LEETCODE_LEETCODE1408_H
