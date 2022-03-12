//
// Created by luzh on 2021/9/5.
//

#include "Solution470.h"
#include <algorithm>

int Solution470::rand10() {
    while (true) {
        int a = rand7();
        int b = rand7();
        int num = (a - 1) * 7 + b;
        if (num <= 40) {
            return num % 10 + 1;
        }
        a = num - 40; // rand9;
        b = rand7();
        num = (a - 1) * 7 + b; // rand63;
        if (num <= 60) {
            return num % 10 + 1;
        }
        a = num - 60; // rand3
        b = rand7();
        num = (a - 1) * 7 + b; // rand21;
        if (num <= 20) {
            return num % 10 + 1;
        }
    }
}

int Solution470::rand7() {
    return random() % 7 + 1;
}
