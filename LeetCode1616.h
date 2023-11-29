//
// Created by 陆泽辉 on 2023/3/18.
//

#ifndef LEETCODE_LEETCODE1616_H
#define LEETCODE_LEETCODE1616_H

#include <string>

using namespace std;

class LeetCode1616 {
public:
    bool checkPalindromeFormation(string a, string b);

private:
    bool checkPalindromeFormationHelper(string a, string b);
};


#endif //LEETCODE_LEETCODE1616_H
