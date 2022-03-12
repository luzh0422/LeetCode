//
// Created by luzh on 2021/10/18.
//

#include "Solution476.h"

int Solution476::findComplement(int num) {
    /**
     * 最高位1 的位置；
     */
    int index = 0;
    while (index <= 30) {
        int temp = 1 << index;
        if (temp > num) {
            break;
        }
        index++;
    }
    int complement = index == 31 ? 0x7fffffff : (1 << index) - 1;
    return num ^ complement;
}
