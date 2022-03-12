//
// Created by luzh on 2021/12/10.
//

#ifndef LEETCODE_SOLUTION748_H
#define LEETCODE_SOLUTION748_H

#include <string>
#include <vector>

using namespace std;

class Solution748 {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words);

private:
    vector<int> getCharNums(string& word);
    bool judgeArr(vector<int>& arr1, vector<int>& arr2);
};


#endif //LEETCODE_SOLUTION748_H
