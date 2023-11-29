//
// Created by 陆泽辉 on 2023/4/27.
//

#ifndef LEETCODE_LEETCODE1048_H
#define LEETCODE_LEETCODE1048_H

#include <string>
#include <vector>

using namespace std;

class LeetCode1048 {
public:
    int longestStrChain(vector<string>& words);

private:
    bool isStrChain(string& word1, string& word2);
};


#endif //LEETCODE_LEETCODE1048_H
