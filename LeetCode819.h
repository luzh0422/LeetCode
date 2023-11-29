//
// Created by 陆泽辉 on 2022/4/17.
//

#ifndef LEETCODE_LEETCODE819_H
#define LEETCODE_LEETCODE819_H

#include <string>
#include <vector>

using namespace std;

class LeetCode819 {
public:
    string mostCommonWord(string paragraph, vector<string>& banned);

private:
    string sToLower(string& s);
};


#endif //LEETCODE_LEETCODE819_H
