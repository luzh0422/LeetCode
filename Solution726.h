//
// Created by luzh on 2021/7/5.
//

#ifndef LEETCODE_SOLUTION726_H
#define LEETCODE_SOLUTION726_H

#include <string>
#include <map>

using namespace std;

class Solution726 {
public:
    string countOfAtoms(string formula);

private:
    string countOfAtoms(string formula, int start, int end, int num);
};


#endif //LEETCODE_SOLUTION726_H
