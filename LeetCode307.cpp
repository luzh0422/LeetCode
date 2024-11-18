//
// Created by 陆泽辉 on 2022/4/4.
//

#include "LeetCode307.h"

namespace {

    void NumArray::build(int index, int left, int right, vector<int> &nums) {
        if (left == right) {
            segamentTree[index] = nums[left];
            return;
        }
        int middle = (left + right) / 2;
        build(index * 2 + 1, left, middle, nums);
        build(index * 2 + 2, middle + 1, right, nums);
        segamentTree[index] = segamentTree[index * 2 + 1] + segamentTree[index * 2 + 2];
    }

    void NumArray::change(int index, int val, int node, int left, int right) {
        if (left == right) {
            segamentTree[node] = val;
            return;
        }
        int middle = (left + right) / 2;
        if (index <= middle) {
            change(index, val, node * 2 + 1, left, middle);
        } else {
            change(index, val, node * 2 + 2, middle + 1, right);
        }
        segamentTree[node] = segamentTree[node * 2 + 1] + segamentTree[node * 2 + 2];
    }

    int NumArray::range(int left, int right, int node, int s, int e) {
        if (left == s && right == e) {
            return segamentTree[node];
        }
        int middle = (s + e) / 2;
        if (right <= middle) {
            return range(left, right, node * 2 + 1, s, middle);
        } else if (left > middle) {
            return range(left, right, node * 2 + 2, middle + 1, e);
        } else {
            return range(left, middle, node * 2 + 1, s, middle) + range(middle + 1, right, node * 2 + 2, middle + 1, e);
        }
    }

    NumArray::NumArray(vector<int> &nums) {
        this->n = nums.size();
        segamentTree.resize(4 * this->n);
        this->build(0, 0, this->n - 1, nums);
    }

    int NumArray::sumRange(int left, int right) {
        return this->range(left, right, 0, 0, n - 1);
    }

    void NumArray::update(int index, int val) {
        this->change(index, val, 0, 0, this->n - 1);
    }
}
