//
// Created by 陆泽辉 on 2023/1/18.
//

#ifndef LEETCODE_LEETCODE1825_H
#define LEETCODE_LEETCODE1825_H

#include <vector>
#include <queue>
#include <set>

using namespace std;

class MKAverage {
public:
    MKAverage(int m, int k);

    void addElement(int num);

    int calculateMKAverage();

private:
    int m, k;
    queue<int> q;
    multiset<int> s1, s2, s3;
    long long sum2;
};


#endif //LEETCODE_LEETCODE1825_H
