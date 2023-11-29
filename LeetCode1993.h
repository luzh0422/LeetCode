//
// Created by 陆泽辉 on 2023/9/24.
//

#ifndef LEETCODE_LEETCODE1993_H
#define LEETCODE_LEETCODE1993_H

#include <vector>

using namespace std;

class LockingTree {
public:
    LockingTree(vector<int>& parent);

    bool lock(int num, int user);

    bool unlock(int num, int user);

    bool upgrade(int num, int user);

private:
    vector<int> parent_;
    vector<int> lockedUsers_;
    vector<vector<int>> children_;
};



#endif //LEETCODE_LEETCODE1993_H
