//
// Created by luzehui on 2024/4/26.
//

#include "LeetCode1146.h"

SnapshotArray::SnapshotArray(int length) {
    snaps.resize(length, unordered_map<int, int>());
}

void SnapshotArray::set(int index, int val) {
    if (snaps[index].count(currSnapId)) {
        snaps[index][currSnapId] = val;
    } else {
        snaps[index].insert(unordered_map<int, int>::value_type(currSnapId, val));
    }
}

int SnapshotArray::get(int index, int snap_id) {
    while (snap_id >= 0) {
        if (snaps[index].count(snap_id)) {
            return snaps[index][snap_id];
        }
        snap_id--;
    }
    return 0;
}

int SnapshotArray::snap() {
    return currSnapId++;
}
