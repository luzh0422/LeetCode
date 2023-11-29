//
// Created by 陆泽辉 on 2022/6/12.
//

#ifndef LEETCODE_LEETCODE890_H
#define LEETCODE_LEETCODE890_H

#include <string>
#include <vector>

using namespace std;

class LeetCode890 {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern);

private:
    bool match(string& s1, string& s2);
};


#endif //LEETCODE_LEETCODE890_H
