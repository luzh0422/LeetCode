//
// Created by luzh on 2021/6/17.
//

#ifndef LEETCODE_SOLUTION65_H
#define LEETCODE_SOLUTION65_H

#include <string>

using namespace std;

class Solution65 {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    };
public:
    CharType toCharType(char ch);
    bool isNumber(string s);
};


#endif //LEETCODE_SOLUTION65_H
