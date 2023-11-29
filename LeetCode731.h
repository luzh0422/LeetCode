//
// Created by 陆泽辉 on 2022/7/19.
//

#ifndef LEETCODE_LEETCODE731_H
#define LEETCODE_LEETCODE731_H

#include <vector>

using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo();
    bool book(int start, int end);

private:
    vector<pair<int, int>> storesOne;
    vector<pair<int, int>> storesTwo;
};


#endif //LEETCODE_LEETCODE731_H
