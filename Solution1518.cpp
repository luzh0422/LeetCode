//
// Created by luzh on 2021/12/17.
//

#include "Solution1518.h"

int Solution1518::numWaterBottles(int numBottles, int numExchange) {
    return numWaterBottles(numBottles, numExchange, 0);
}

int Solution1518::numWaterBottles(int numBottles, int numExchange, int emptyBottles) {
    if (numBottles == 0) {
        return 0;
    } else {
        if (numBottles + emptyBottles < numExchange) {
            return 0;
        } else {
            int temp = (numBottles + emptyBottles) / numExchange;
            emptyBottles = (numBottles + emptyBottles) % numExchange;
            return numBottles + numWaterBottles(temp, numExchange, emptyBottles);
        }
    }
}
