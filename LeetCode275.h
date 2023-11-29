//
// Created by luzehui on 2023/10/29.
//

#ifndef LEETCODE_LEETCODE275_H
#define LEETCODE_LEETCODE275_H

#include <vector>

using namespace std;

class LeetCode275 {
public:
    int hIndex(vector<int>& citations);

private:
    int binarySearch(vector<int>& citations, int target);
};


#endif //LEETCODE_LEETCODE275_H
