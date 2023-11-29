//
// Created by 陆泽辉 on 2022/11/8.
//

#ifndef LEETCODE_LEETCODE816_H
#define LEETCODE_LEETCODE816_H

#include <string>
#include <vector>

using namespace std;

class LeetCode816 {
public:
    vector<string> ambiguousCoordinates(string s);

private:
    vector<string> ambiguousCoordinatesHelper(string s, int dotIndex);
    bool judgeNumber(string s);
};


#endif //LEETCODE_LEETCODE816_H
