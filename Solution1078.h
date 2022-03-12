//
// Created by luzh on 2021/12/26.
//

#ifndef LEETCODE_SOLUTION1078_H
#define LEETCODE_SOLUTION1078_H

#include <string>
#include <vector>

using namespace std;

class Solution1078 {
public:
    vector<string> findOcurrences(string text, string first, string second);

private:
    vector<string> parseString(string text);
};


#endif //LEETCODE_SOLUTION1078_H
