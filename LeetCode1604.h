//
// Created by 陆泽辉 on 2023/2/7.
//

#ifndef LEETCODE_LEETCODE1604_H
#define LEETCODE_LEETCODE1604_H

#include <string>
#include <vector>

using namespace std ;

class LeetCode1604 {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime);

private:
    int timeDelta(pair<int, int>& time1, pair<int, int>& time2);
};


#endif //LEETCODE_LEETCODE1604_H
