//
// Created by luzh on 2022/2/10.
//

#ifndef LEETCODE_SOLUTION1447_H
#define LEETCODE_SOLUTION1447_H

#include <string>
#include <vector>

using namespace std;

class Solution1447 {
public:
    vector<string> simplifiedFractions(int n);

private:
    bool isSimplifiedFraction(int a, int b);
};


#endif //LEETCODE_SOLUTION1447_H
