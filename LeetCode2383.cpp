//
// Created by 陆泽辉 on 2023/3/13.
//

#include "LeetCode2383.h"

#include <numeric>

int LeetCode2383::minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience) {
    int energyTotal = accumulate(energy.begin(), energy.end(), 0);
    int experienceDelta = 0, experienceCurr = initialExperience;
    for (int i = 0; i < experience.size(); i++) {
        if (experience[i] >= experienceCurr) {
            experienceDelta += experience[i] - experienceCurr + 1;
            experienceCurr = 2 * experience[i] + 1;
        } else {
            experienceCurr += experience[i];
        }
    }
    return max(energyTotal - initialEnergy + 1, 0) +  experienceDelta;
}
