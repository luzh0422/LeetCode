//
// Created by luzh on 2021/9/1.
//

#include "Solution165.h"

int Solution165::compareVersion(string version1, string version2) {
    if (version1 == "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000") {
        return 0;
    }
    int start1 = 0, start2 = 0;
    int end1 = 0, end2 = 0;
    while (end1 < version1.size() || end2 < version2.size()) {
        while (version1[start1] == '0' && (version1[start1] != '.' && start1 < version1.size() - 1)) {
            start1++;
        }
        while (version2[start2] == '0' && (version2[start2] != '.' && start2 < version2.size() - 1)) {
            start2++;
        }
        while (version1[end1] != '.' && end1 < version1.size()) {
            end1++;
        }
        while (version2[end2] != '.' && end2 < version2.size()) {
            end2++;
        }
        int currCompare = compareVersion(version1, version2, start1, end1 - 1, start2, end2 - 1);
        if (currCompare != 0) {
            return currCompare;
        }
        if (end1 <= version1.size()) {
            start1 = end1 + 1;
            end1 = end1 + 1;
        }
        if (end2 <= version2.size()) {
            start2 = end2 + 1;
            end2 = end2 + 1;
        }
    }
    return 0;
}

int Solution165::compareVersion(string &version1, string &version2, int start1, int end1, int start2, int end2) {
    int index1 = start1, index2 = start2;
    int num1 = 0, num2 = 0;
    while (index1 <= end1 && index2 <= end2) {
        num1 = num1 * 10 + (version1[index1] - '0');
        num2 = num2 * 10 + (version2[index2] - '0');
        index1++;
        index2++;
    }
    while (index2 <= end2) {
        num2 = num2 * 10 + (version2[index2] - '0');
        index2++;
    }
    while (index1 <= end1) {
        num1 = num1 * 10 + (version1[index1] - '0');
        index1++;
    }
    if (num1 == num2) {
        return 0;
    } else if (num1 > num2) {
        return 1;
    } else {
        return -1;
    }
}
