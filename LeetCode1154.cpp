//
// Created by luzehui on 2023/12/31.
//

#include "LeetCode1154.h"

int LeetCode1154::dayOfYear(std::string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 7));
    int day = stoi(date.substr(8, 10));
    vector<int> monthDay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = 0;
    for (int i = 0; i < month - 1; i++) {
        res += monthDay[i];
    }
    if (month > 2 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)) {
        res += 1;
    }
    res += day;
    return res;
}
