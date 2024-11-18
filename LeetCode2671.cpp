//
// Created by luzehui on 2024/3/21.
//

#include "LeetCode2671.h"

FrequencyTracker::FrequencyTracker() {

}

void FrequencyTracker::add(int number) {
    if (numberOrder.count(number)) {
        int num = numberOrder[number];
        if (frequencyOrder.count(num)) {
            frequencyOrder[num]--;
        }
        num = ++numberOrder[number];
        if (frequencyOrder.count(num)) {
            frequencyOrder[num]++;
        } else {
            frequencyOrder.insert(unordered_map<int, int>::value_type(num, 1));
        }
    } else {
        numberOrder.insert(unordered_map<int, int>::value_type(number, 1));
        if (frequencyOrder.count(1)) {
            frequencyOrder[1]++;
        } else {
            frequencyOrder.insert(unordered_map<int, int>::value_type(1, 1));
        }
    }
}

void FrequencyTracker::deleteOne(int number) {
    if (numberOrder.count(number) && numberOrder[number] != 0) {
        int num = numberOrder[number];
        frequencyOrder[num]--;
        num = --numberOrder[number];
        if (frequencyOrder.count(num)) {
            frequencyOrder[num]++;
        } else {
            frequencyOrder.insert(unordered_map<int, int>::value_type(num, 1));
        }
    }
}

bool FrequencyTracker::hasFrequency(int frequency) {
    return frequencyOrder.count(frequency) && frequencyOrder[frequency] != 0;
}
