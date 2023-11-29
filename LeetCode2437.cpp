//
// Created by 陆泽辉 on 2023/5/9.
//

#include "LeetCode2437.h"

int LeetCode2437::countTime(string time) {
    string hour = time.substr(0, 2);
    string minute = time.substr(3, 2);
    int hourCount = 1;
    if (hour[0] == '?') {
        if (hour[1] == '?') {
            hourCount = 24;
        } else if (hour[1] - '0' < 4) {
            hourCount = 3;
        } else if (hour[1] - '0' == 4) {
            if (stoi(minute) == 0) {
                hourCount = 3;
            } else {
                hourCount = 2;
            }
        } else {
            hourCount = 2;
        }
    } else if (hour[1] == '?') {
        if (hour[0] - '0' < 2) {
            hourCount = 10;
        } else {
            hourCount = 4;
        }
    }
    int minuteCount = 1;
    if (minute[0] == '?') {
        if (minute[1] == '?') {
            minuteCount = 60;
        } else {
            minuteCount = 6;
        }
    } else if (minute[1] == '?') {
        if (minute[0] == '6') {
            minuteCount = 1;
        } else {
            minuteCount = 10;
        }
    }
    return hourCount * minuteCount;
}
