//
// Created by luzh on 2021/7/24.
//

#include "Solution1736.h"

string Solution1736::maximumTime(string time) {
    for (int i = 0; i < time.size(); i++) {
        if (i == 0) {
            if (time[i] == '?' ) {
                if (time[i + 1] == '?' || time[i + 1] < '4') {
                    time[i] = '2';
                } else {
                    time[i] = '1';
                }
            }
        } else if (i == 1) {
            if (time[i] == '?') {
                if (time[i - 1] < '2') {
                    time[i] = '9';
                } else {
                    time[i] = '3';
                }
            }
        } else if (i == 3) {
            if (time[i] == '?') {
                time[i] = '5';
            }
        } else if (i == 4) {
            if (time[i] == '?') {
                time[i] = '9';
            }
        }
    }
    return time;
}
