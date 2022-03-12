//
// Created by luzh on 2021/11/30.
//

#include "Solution400.h"
#include <math.h>


/**
 * 1 - 9 一共有9个位置；
 * 10 - 99 一共有 2 * 9 * 10个位置；
 * 100 - 999 一共有 3 * 9 * 100个位置；
 * 。。。
 * 因此可以先判断数字是在哪个区域；
 * 以n = 102为例，它一定落在10 - 99；
 * 然后判断n 出现在这个范围内的第几个数字： (n - 9) / 2；为什么要除以2，因为这个范围内，每个数字有两位；
 * 找到对应的数字后，判断是这个数字的第几位；(n - 9) % 2；
 * 找到数字和位数后，就可以返回对应的数字了。
 * @param n
 * @return
 */
int Solution400::findNthDigit(int n) {
    int base = 1, count = 9;
    int curr = base * count;
    while (curr < n) {
        n -= curr;
        base += 1;
        count *= 10;
        curr = base * count;
    }
    int temp = pow(10, base - 1);
    int index = (n - 1) / base; // 范围内的第几个数字；
    int step = (n - 1) % base; // 取数字的第几位；
    return (temp + index) / int(pow(10, base - step - 1)) % 10;
}
