//
// Created by 陆泽辉 on 2022/7/5.
//

#ifndef LEETCODE_LEETCODE729_H
#define LEETCODE_LEETCODE729_H

#include <vector>

using namespace std;

class MyCalendar {
public:
    MyCalendar();

    bool book(int start, int end);

private:
    int binarySearch(vector<int>& arr, int target);
    vector<vector<int>> calendar;
    vector<int> starts;
    vector<int> ends;
};

#endif //LEETCODE_LEETCODE729_H
