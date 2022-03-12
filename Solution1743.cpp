//
// Created by luzh on 2021/7/25.
//

#include "Solution1743.h"
#include <unordered_map>
#include <queue>

vector<int> Solution1743::restoreArray(vector<vector<int>> &adjacentPairs) {
    unordered_map<int, int> inDegree = {};
    int n = adjacentPairs.size() + 2;
    /**
     * 构建图和计算入度；
     */
    for (auto& adjacentPair : adjacentPairs) {
        if (inDegree.count(adjacentPair[0])) {
            inDegree[adjacentPair[0]] ++;
        } else {
            inDegree[adjacentPair[0]] = 1;
        }
        if (inDegree.count(adjacentPair[1])) {
            inDegree[adjacentPair[1]] ++;
        } else {
            inDegree[adjacentPair[1]] = 1;
        }
    }
    vector<int> ret;
    /**
     * 找到入度为1的节点作为开始；
     */
    int start = 0;
    for (auto it = inDegree.begin(); it != inDegree.end(); it++) {
        if (it->second == 1) {
            start = it->first;
            break;
        }
    }
    int tag = true;
    while (tag) {
        tag = false;
        ret.push_back(start);
        inDegree[start]--;
        for (auto& adjacentPair : adjacentPairs) {
            if (adjacentPair[0] == start) {
                if (inDegree[adjacentPair[1]] == 2) {
                    inDegree[adjacentPair[1]] --;
                    start = adjacentPair[1];
                    tag = true;
                    break;
                }
            } else if (adjacentPair[1] == start) {
                if (inDegree[adjacentPair[0]] == 2) {
                    inDegree[adjacentPair[0]] --;
                    start = adjacentPair[0];
                    tag = true;
                    break;
                }
            }
        }
    }
    for (auto it = inDegree.begin(); it != inDegree.end(); it++) {
        if (it->second == 1) {
            ret.push_back(it->first);
            break;
        }
    }
    return ret;
}
