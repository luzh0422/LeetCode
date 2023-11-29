//
// Created by 陆泽辉 on 2022/11/25.
//

#ifndef LEETCODE_LEETCODE809_H
#define LEETCODE_LEETCODE809_H

#include <string>
#include <vector>

using namespace std;

class LeetCode809 {
public:
    int expressiveWords(string s, vector<string>& words);

private:
    int expressiveWords(string& s, string& word);
};


#endif //LEETCODE_LEETCODE809_H
