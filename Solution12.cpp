//
// Created by luzh on 2021/5/14.
//

#include "Solution12.h"

string Solution12::intToRoman(int num) {
    string ans = "";

    while (num != 0) {
        ans += intToRomanHelper(num);
    }
    return ans;
}

string Solution12::intToRomanHelper(int& num) {
    if (num == 4) {
        num = 0;
        return "IV";
    }
    if (num == 9) {
        num = 0;
        return "IX";
    }
    if (num - 40 >= 0 && num - 40 <= 9) {
        num -= 40;
        return "XL";
    }
    if (num - 90 >= 0 && num - 90 <= 9) {
        num -= 90;
        return "XC";
    }
    if (num - 400 >= 0 && num - 400 <= 99) {
        num -= 400;
        return "CD";
    }
    if (num - 900 >= 0 && num - 900 <= 99) {
        num -= 900;
        return "CM";
    }
    int count = 0;
    string ans = "";
    if (num >= 1000) {
        count = num / 1000;
        num %= 1000;
        for (int i = 0; i < count; i++) {
            ans += 'M';
        }
    } else if (num >= 500) {
        count = num / 500;
        num %= 500;
        for (int i = 0; i < count; i++) {
            ans += "D";
        }
    } else if (num >= 100) {
        count = num / 100;
        num %= 100;
        for (int i = 0; i < count; i++) {
            ans += "C";
        }
    } else if (num >= 50) {
        count = num / 50;
        num %= 50;
        for (int i = 0; i < count; i++) {
            ans += "L";
        }
    } else if (num >= 10) {
        count = num / 10;
        num %= 10;
        for (int i = 0; i < count; i++) {
            ans += "X";
        }
    } else if (num >= 5) {
        count = num / 5;
        num %= 5;
        for (int i = 0; i < count; i++) {
            ans += "V";
        }
    } else if (num >= 1) {
        count = num / 1;
        num %= 1;
        for (int i = 0; i < count; i++) {
            ans += 'I';
        }
    }
    return ans;
}
