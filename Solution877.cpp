//
// Created by luzh on 2021/6/16.
//

#include "Solution877.h"

bool Solution877::stoneGame(vector<int> &piles) {
    int size = piles.size();
    vector<int> record(size);
    return alexStoneGame(piles, record, 0, 0, 0);
}

bool Solution877::alexStoneGame(vector<int> &piles, vector<int> &record, int alexStones, int liStones, int pickNum) {
    int size = piles.size();
    if (pickNum == size) {
        /**
         * 这种场景，alex赢得比赛；
         */
        if (alexStones > liStones) {
            return true;
        } else {
            return false;
        }
    }
    bool ans = false;
    for (int i = 0; i< size; i++) {
        if (record[i] == 0) {
            record[i] = 1;
            ans |= liStoneGame(piles, record, alexStones + piles[i], liStones, pickNum + 1);
            record[i] = 0;
        }
    }
    return ans;
}

bool Solution877::liStoneGame(vector<int> &piles, vector<int> &record, int alexStones, int liStones, int pickNum) {
    int size = piles.size();
    if (pickNum == size) {
        /**
         * 这种场景，alex赢得比赛；
         */
        if (liStones > alexStones) {
            return true;
        } else {
            return false;
        }
    }
    bool ans = false;
    for (int i = 0; i< size; i++) {
        if (record[i] == 0) {
            record[i] = 1;
            ans |= alexStoneGame(piles, record, alexStones, liStones + piles[i], pickNum + 1);
            record[i] = 0;
        }
    }
    return !ans;
}
