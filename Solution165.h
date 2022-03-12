//
// Created by luzh on 2021/9/1.
//

#ifndef LEETCODE_SOLUTION165_H
#define LEETCODE_SOLUTION165_H

#include <string>

using namespace std;

class Solution165 {
public:
    int compareVersion(string version1, string version2);

public:
    int compareVersion(string& version1, string& version2, int start1, int end1, int start2, int end2);
};


#endif //LEETCODE_SOLUTION165_H
