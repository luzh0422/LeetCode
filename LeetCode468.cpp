//
// Created by 陆泽辉 on 2022/5/29.
//

#include "LeetCode468.h"

string LeetCode468::validIPAddress(string queryIP) {
    if (isIPV4(queryIP)) {
        return "IPv4";
    }
    if (isIPV6(queryIP)) {
        return "IPv6";
    }
    return "Neither";
}

bool LeetCode468::isIPV4(string &queryIP) {
    int num = -1, n = queryIP.size();
    int numCount = 0;
    for (int i = 0; i < n; i++) {
        if (num == -1 && queryIP[i] =='0' && i < n - 1 && queryIP[i + 1] != '.') {
            /**
             * 0开头的数字；
             */
            return false;
        } else if (queryIP[i] >= '0' && queryIP[i] <= '9') {
            if (num == -1) {
                num = 0;
            }
            num = num * 10 + queryIP[i] - '0';
            if (num >= 0x3f3f3f3f) {
                return false;
            }
        } else if (queryIP[i] == '.') {
            numCount++;
            if (num < 0 || num > 255) {
                return false;
            }
            num = -1;
        } else if (queryIP[i] < '0' || queryIP[i] > '9') {
            return false;
        }
    }
    if (numCount != 3 || num < 0 || num > 255) {
        return false;
    }
    return true;
}

bool LeetCode468::isIPV6(string &queryIP) {
    int n = queryIP.size();
    int numCount = 0;
    if (n > 39) {
        return false;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (queryIP[i] == ':') {
            if (count > 4 || count == 0) {
                return false;
            }
            numCount++;
            count = 0;
        } else if (!(queryIP[i] >= '0' && queryIP[i] <= '9' || queryIP[i] >= 'a' && queryIP[i] <= 'f' || queryIP[i] >= 'A' && queryIP[i] <= 'F')) {
            return false;
        } else {
            count++;
        }
    }
    if (count > 4 || count == 0 || numCount != 7) {
        return false;
    }
    return true;
}
