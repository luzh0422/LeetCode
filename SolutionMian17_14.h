//
// Created by luzh on 2021/9/3.
//

#ifndef LEETCODE_SOLUTIONMIAN17_14_H
#define LEETCODE_SOLUTIONMIAN17_14_H

#include <vector>

using namespace std;

class SolutionMian17_14 {
public:
    vector<int> smallestK(vector<int>& arr, int k);

private:
    void insert(vector<int>& minHeap, int val);
    int pop(vector<int>& minHeap);
};


#endif //LEETCODE_SOLUTIONMIAN17_14_H
