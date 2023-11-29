//
// Created by 陆泽辉 on 2023/4/17.
//

#include "LeetCode2409.h"

int LeetCode2409::countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    const int MONTHDAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int arriveAliceMonth = stoi(arriveAlice.substr(0, 2));
    int arriveAliceDay = stoi(arriveAlice.substr(3, 2));
    int leaveAliceMonth = stoi(leaveAlice.substr(0, 2));
    int leaveAliceDay = stoi(leaveAlice.substr(3, 2));
    int arriveBobMonth = stoi(arriveBob.substr(0, 2));
    int arriveBobDay = stoi(arriveBob.substr(3, 2));
    int leaveBobMonth = stoi(leaveBob.substr(0, 2));
    int leaveBobDay = stoi(leaveBob.substr(3, 2));
if (leaveAliceMonth < arriveBobMonth || leaveAliceMonth == arriveBobMonth && leaveAliceDay < arriveBobDay || arriveAliceMonth == leaveBobMonth && leaveBobDay < arriveAliceDay) {
        return 0;
    }
    int arriveMonth, arriveDay, leaveMonth, leaveDay;
    if (arriveAliceMonth > arriveBobMonth) {
        arriveMonth = arriveAliceMonth;
        arriveDay = arriveAliceDay;
    } else if (arriveAliceMonth < arriveBobMonth) {
        arriveMonth = arriveBobMonth;
        arriveDay = arriveBobDay;
    } else {
        arriveBobMonth = arriveAliceMonth;
        arriveDay = max(arriveAliceDay, arriveBobDay);
    }
    if (leaveAliceMonth < leaveBobMonth) {
        leaveMonth = leaveAliceMonth;
        leaveDay = leaveAliceDay;
    } else if (leaveAliceMonth > leaveBobMonth) {
        leaveMonth = leaveBobMonth;
        leaveDay = leaveBobDay;
    } else {
        leaveMonth = leaveAliceMonth;
        leaveDay = min(leaveAliceDay, leaveBobDay);
    }
    int res = 0;
    for (int i = arriveMonth; i <= leaveMonth; i++) {
        if (i == arriveMonth && i == leaveMonth) {
            res += leaveDay - arriveDay + 1;
        } else if (i == arriveMonth) {
            res += MONTHDAY[i - 1] - arriveDay + 1;
        } else if (i == leaveMonth) {
            res += leaveDay;
        } else {
            res += MONTHDAY[i - 1];
        }
    }
    return res;
}
