//
// Created by luzh on 2021/4/4.
//

#include "Solution781.h"

int Solution781::numRabbits(vector<int> &answers) {
    if (answers.size() == 0) return 0;
    std::sort(answers.begin(), answers.end());
    int ans = 0;
    int temp = answers[0];
    ans += 1 + temp;
    int step = 0;
    for (int i = 1; i < answers.size(); i++) {
        if (step < temp && answers[i] == temp) {
            step++;
        } else {
            step = 0;
            temp = answers[i];
            ans += 1 + temp;
        }
    }
    return ans;
}
