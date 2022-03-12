//
// Created by luzh on 2021/11/28.
//

#ifndef LEETCODE_SOLUTION483_H
#define LEETCODE_SOLUTION483_H

#include <vector>
#include <string>

using namespace std;

class Solution483 {
public:
    vector<int> findAnagrams(string s, string p);

private:
    int sToI(string s);
    void sortString(string& s);
};


#endif //LEETCODE_SOLUTION483_H
