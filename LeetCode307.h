//
// Created by 陆泽辉 on 2022/4/4.
//

#ifndef LEETCODE_LEETCODE307_H
#define LEETCODE_LEETCODE307_H

#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums);
    void update(int index, int val);
    int sumRange(int left, int right);

private:
    void build(int index, int left, int right, vector<int>& nums);
    void change(int index, int val, int node, int left, int right);
    int range(int left, int right, int node, int s, int e);
    vector<int> segamentTree;
    int n;
};


#endif //LEETCODE_LEETCODE307_H
