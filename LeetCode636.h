//
// Created by 陆泽辉 on 2022/8/7.
//

#ifndef LEETCODE_LEETCODE636_H
#define LEETCODE_LEETCODE636_H

#include <string>
#include <vector>

using namespace std;

class LeetCode636 {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs);

private:
    vector<string> parseLog(string& log);
};


#endif //LEETCODE_LEETCODE636_H
