//
// Created by luzehui on 2024/3/21.
//

#ifndef LEETCODE_LEETCODE2671_H
#define LEETCODE_LEETCODE2671_H

#include <unordered_map>

using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker();

    void add(int number);

    void deleteOne(int number);

    bool hasFrequency(int frequency);

private:
    unordered_map<int, int> numberOrder;
    unordered_map<int, int> frequencyOrder;
};

#endif //LEETCODE_LEETCODE2671_H
