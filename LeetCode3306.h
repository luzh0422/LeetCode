//
// Created by luzehui on 25-3-13.
//

#ifndef LEETCODE_LEETCODE3306_H
#define LEETCODE_LEETCODE3306_H

#include <string>

using namespace std;

class LeetCode3306 {
public:
    long long countOfSubstrings(string word, int k);

private:
    long long countOfSubstringsHelp(string& word, int k);
};


#endif //LEETCODE_LEETCODE3306_H
