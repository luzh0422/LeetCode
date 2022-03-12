//
// Created by luzh on 2021/12/21.
//

#include "Solution1154.h"

int Solution1154::dayOfYear(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    int ans = 0;
    if (isLeapYear(year)) {
        switch (month) {
            case 1:
                ans += day;
                break;
            case 2:
                ans += 31;
                ans += day;
                break;
            case 3:
                ans += 31 + 29;
                ans += day;
                break;
            case 4:
                ans += 31 + 29 + 31;
                ans += day;
                break;
            case 5:
                ans += 31 + 29 + 31 + 30;
                ans += day;
                break;
            case 6:
                ans += 31 + 29 + 31 + 30 + 31;
                ans += day;
                break;
            case 7:
                ans += 31 + 29 + 31 + 30 + 31 + 30;
                ans += day;
                break;
            case 8:
                ans += 31 + 29 + 31 + 30 + 31 + 30 + 31;
                ans += day;
                break;
            case 9:
                ans += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
                ans += day;
                break;
            case 10:
                ans += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                ans += day;
                break;
            case 11:
                ans += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                ans += day;
                break;
            case 12:
                ans += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                ans += day;
                break;
        }
    } else {
        switch (month) {
            case 1:
                ans += day;
                break;
            case 2:
                ans += 31;
                ans += day;
                break;
            case 3:
                ans += 31 + 28;
                ans += day;
                break;
            case 4:
                ans += 31 + 28 + 31;
                ans += day;
                break;
            case 5:
                ans += 31 + 28 + 31 + 30;
                ans += day;
                break;
            case 6:
                ans += 31 + 28 + 31 + 30 + 31;
                ans += day;
                break;
            case 7:
                ans += 31 + 28 + 31 + 30 + 31 + 30;
                ans += day;
                break;
            case 8:
                ans += 31 + 28 + 31 + 30 + 31 + 30 + 31;
                ans += day;
                break;
            case 9:
                ans += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
                ans += day;
                break;
            case 10:
                ans += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                ans += day;
                break;
            case 11:
                ans += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                ans += day;
                break;
            case 12:
                ans += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                ans += day;
                break;
        }
    }
    return ans;
}

bool Solution1154::isLeapYear(int year) {
    if (year % 100 == 0 && year % 400 == 0 || year % 100 != 0 && year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}
