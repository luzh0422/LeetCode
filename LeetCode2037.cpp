//
// Created by 陆泽辉 on 2022/12/31.
//

#include "LeetCode2037.h"

int LeetCode2037::minMovesToSeat(vector<int> &seats, vector<int> &students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int res = 0;
    int n = seats.size();
    for (int i = 0; i < n; i++) {
        res += abs(students[i] - seats[i]);
    }
    return res;
}
