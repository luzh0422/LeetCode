//
// Created by 陆泽辉 on 2023/1/16.
//

#ifndef LEETCODE_LEETCODE1813_H
#define LEETCODE_LEETCODE1813_H

#include <string>
#include <vector>

using namespace std;

class LeetCode1813 {
public:
    bool areSentencesSimilar(string sentence1, string sentence2);

private:
    vector<string> stringToArray(string& sentence);
};


#endif //LEETCODE_LEETCODE1813_H
