//
// Created by luzehui on 2024/4/26.
//

#ifndef LEETCODE_LEETCODE1146_H
#define LEETCODE_LEETCODE1146_H

#include <vector>
#include <unordered_map>

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length);

    void set(int index, int val);

    int snap();

    int get(int index, int snap_id);

private:
    vector<unordered_map<int, int>> snaps;
    int currSnapId = 0;
};

#endif //LEETCODE_LEETCODE1146_H
