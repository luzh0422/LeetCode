//
// Created by luzh on 2021/12/31.
//

#include "Solution507.h"

bool Solution507::checkPerfectNumber(int num) {
    int index = 2;
    int temp = 1;
    while (index * index <= num) {
        if (num % index == 0) {
            temp += index;
            if (num / index != index) {
                temp += num / index;
            }
        }
        index++;
    }
    return temp == num;
}
