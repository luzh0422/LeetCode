//
// Created by luzh on 2021/3/19.
//

#ifndef LEETCODE_SOLUTION1603_H
#define LEETCODE_SOLUTION1603_H


class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->bigType = big;
        this->mediumType = medium;
        this->smallType = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (this->bigType == 0) {
                return false;
            } else {
                this->bigType--;
            }
        }
        if (carType == 2) {
            if (this->mediumType == 0) {
                return false;
            } else {
                this->mediumType--;
            }
        }
        if (carType == 3) {
            if (this->smallType == 0) {
                return false;
            } else {
                this->smallType--;
            }
        }
        return true;
    }

private:
    int bigType = 0;
    int mediumType = 0;
    int smallType = 0;
};


#endif //LEETCODE_SOLUTION1603_H
