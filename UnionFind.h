//
// Created by luzh on 2021/10/14.
//

#ifndef LEETCODE_UNIONFIND_H
#define LEETCODE_UNIONFIND_H

#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int _n);
    int find(int x);
    void unionSet(int x, int y);
private:
    vector<int> parent, rank;
    int n;
    /**
     * 通过setCount可以求出最后是一棵连通子树，还是多棵连通子树。
     */
    int setCount;
};


#endif //LEETCODE_UNIONFIND_H
