//
// Created by 陆泽辉 on 2022/8/21.
//

#ifndef LEETCODE_LEETCODE1455_H
#define LEETCODE_LEETCODE1455_H

#include <string>

using namespace std;

class LeetCode1455 {
public:
    int isPrefixOfWord(string sentence, string searchWord);

private:
    bool isPerfixOfWord(string& s, string& searchWord);
};


#endif //LEETCODE_LEETCODE1455_H
