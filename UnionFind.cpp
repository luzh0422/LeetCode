//
// Created by luzh on 2021/10/14.
//

#include "UnionFind.h"

UnionFind::UnionFind(int _n) {
    n = _n;
    setCount = _n;
    rank.resize(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        /**
         * 初始化每一个节点的parent都指向自己；
         */
        parent[i] = i;
    }
}

/**
 * 找到根节点，同时在查找的过程中，使用了路径压缩法；
 * @param x
 * @return
 */
int UnionFind::find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void UnionFind::unionSet(int x, int y) {
    int xParent = find(x);
    int yParent = find(y);
    if (rank[xParent] > rank[yParent]) {
        parent[yParent] = xParent;
    } else {
        if (rank[xParent] == rank[yParent]) {
            rank[yParent]++;
        }
        parent[xParent] = yParent;
    }
    setCount--;
}

