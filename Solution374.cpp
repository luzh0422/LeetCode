//
// Created by luzh on 2021/6/14.
//

#include "Solution374.h"

int Solution374::guess(int n) {
    if (n > _guess) {
        return -1;
    } else if (n < _guess) {
        return 1;
    } else {
        return 0;
    }
}

int Solution374::guessNumber(int n) {
    int start = 1;
    int end = n;
    int middle = (start + end) / 2;
    while (start < end) {
        if (guess(middle) == -1) {
            end = middle - 1;
            middle = (start + end) / 2;
        } else if (guess(middle) == 1) {
            start = middle + 1;
            middle = (start + end) / 2;
        } else if (guess(middle) == 0) {
            return middle;
        }
    }
    return start;
}
