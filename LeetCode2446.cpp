//
// Created by 陆泽辉 on 2023/5/17.
//

#include "LeetCode2446.h"

bool LeetCode2446::haveConflict(vector<string> &event1, vector<string> &event2) {
    int hour11 = stoi(event1[0].substr(0, 2));
    int minute11 = stoi(event1[0].substr(3, 2));
    int hour12 = stoi(event1[1].substr(0, 2));
    int minute12 = stoi(event1[1].substr(3, 2));
    int hour21 = stoi(event2[0].substr(0, 2));
    int minute21 = stoi(event2[0].substr(3, 2));
    int hour22 = stoi(event2[1].substr(0, 2));
    int minute22 = stoi(event2[1].substr(3, 2));
    if ((hour11 > hour22 || hour21 > hour12) || (hour11 == hour22 && minute22 < minute11) || (hour21 == hour12 && minute12 < minute21)) {
        return false;
    }
    return true;
}
