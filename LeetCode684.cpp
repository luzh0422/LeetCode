//
// Created by luzehui on 2024/10/27.
//

#include "LeetCode684.h"

namespace {
    UnionFind::UnionFind(int n) {
        ranks.resize(n + 1, 1);
        parents.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            /**
             * 初始化每一个节点的parent都指向自己；
             */
            parents[i] = i;
        }
    }

/**
 * 找到根节点，同时在查找的过程中，使用了路径压缩法；
 * @param x
 * @return
 */
    int UnionFind::find(int x) {
        return x == parents[x] ? x : parents[x] = find(parents[x]);
    }

    void UnionFind::unionSet(int x, int y) {
        if (ranks[x] > ranks[y]) {
            parents[y] = x;
        } else {
            if (ranks[x] == ranks[y]) {
                ranks[y]++;
            }
            parents[x] = y;
        }
    }
}

vector<int> LeetCode684::findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    UnionFind unionFind(n);
    for (auto edge : edges) {
        int num1 = edge[0];
        int num2 = edge[1];
        int num1Parent = unionFind.find(num1), num2Parent = unionFind.find(num2);
        if (num1Parent == num2Parent) {
            return edge;
        }
        unionFind.unionSet(num1Parent, num2Parent);
    }
    return {};
}
