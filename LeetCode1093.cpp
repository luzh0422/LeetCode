//
// Created by 陆泽辉 on 2023/5/27.
//

#include "LeetCode1093.h"
#include <numeric>

vector<double> LeetCode1093::sampleStats(vector<int> &count) {
    double mininum = -1.0f, maxinum, mean, median = -1.0f, mode;
    int medianFirst = -1, medianSecond = -1;
    long numCount = accumulate(count.begin(), count.end(), 0);
    double numTotal = 0.0f;
    long currCount = 0;
    long maxCount = 0;
    for (long i = 0; i <= 255; i++) {
        if (count[i] != 0) {
            // 最小数；
            if (mininum == -1.0f) {
                mininum = i;
            }
            // 最大数；
            maxinum = i;
            // 众数；
            if (count[i] > maxCount) {
                maxCount = count[i];
                mode = i;
            }
            numTotal += i * count[i];
            currCount += count[i];
            if (numCount % 2 != 0) {
                if (median == -1.0f && currCount >= (numCount + 1) / 2) {
                    median = i;
                }
            } else {
                if (median == -1.0f) {
                    if (currCount >=  numCount / 2 + 1) {
                        if (medianFirst == -1 && medianSecond == -1) {
                            median = i;
                        } else if (medianSecond == -1) {
                            medianSecond = i;
                            median = static_cast<double>(medianFirst + medianSecond) / 2.0f;
                        }
                    } else if (currCount >= numCount / 2) {
                        if (medianFirst == -1) {
                            medianFirst = i;
                        }
                    }
                }

            }
        }
    }
    // 平均数；
    mean = numTotal / numCount;
    return {mininum, maxinum, mean, median, mode};
}
