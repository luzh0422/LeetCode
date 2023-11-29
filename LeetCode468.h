//
// Created by 陆泽辉 on 2022/5/29.
//

#ifndef LEETCODE_LEETCODE468_H
#define LEETCODE_LEETCODE468_H

#include <string>

using namespace std;

class LeetCode468 {
public:
    string validIPAddress(string queryIP);

private:
    bool isIPV4(string& queryIP);
    bool isIPV6(string& queryIP);
};


#endif //LEETCODE_LEETCODE468_H
