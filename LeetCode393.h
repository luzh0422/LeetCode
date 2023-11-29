//
// Created by 陆泽辉 on 2022/3/13.
//

#ifndef LEETCODE_LEETCODE393_H
#define LEETCODE_LEETCODE393_H

#include <vector>

using namespace std;

class LeetCode393 {
public:
    bool validUtf8(vector<int>& data);

private:
    int nextCount(int data);
    bool validUtf8(int data);
};


#endif //LEETCODE_LEETCODE393_H
