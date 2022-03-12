//
// Created by luzh on 2021/12/11.
//

#ifndef LEETCODE_SOLUTION911_H
#define LEETCODE_SOLUTION911_H

#include <vector>
#include <map>

using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times);

    int q(int t);

private:
    map<int, map<int, int>> records;
    map<int, int> wins;
};


#endif //LEETCODE_SOLUTION911_H
