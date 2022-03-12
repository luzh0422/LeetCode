//
// Created by luzh on 2021/11/25.
//

#include "Solution458.h"


/**
 * minutesToTest = 60; minutesToDie = 15; 则一只猪最多喝4次水，可以测试5只水桶；
 * 那么两只猪最多可以测试 5 * 5 = 25只水桶；
 * 每只猪测试的是一个维度，而不是一只水桶。
 * @param buckets
 * @param minutesToDie
 * @param minutesToTest
 * @return
 */
int Solution458::poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    if (buckets < 2) {
        return  0;
    }
    int base = minutesToTest % minutesToDie == 0 ? minutesToTest / minutesToDie + 1: minutesToTest / minutesToDie + 2;
    int count = base;
    int res = 1;
    while (count < buckets) {
        count = count * base;
        res++;
    }
    return res;
}
