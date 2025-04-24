#include <iostream>
#include <vector>
#include "LeetCode80.h"

#include "TreeNode.h"
#include "LeetCode81.h"
#include "LeetCode59.h"
#include "LeetCode1552.h"
#include "LeetCode2080.h"
#include "LeetCode3306.h"
#include "LeetCode2680.h"
#include "LeetCode2116.h"
#include "LeetCode1863.h"
#include "LeetCode3396.h"
#include "LeetCode1534.h"
#include "LeetCode2537.h"
#include "LeetCode2563.h"
#include "LeetCode2799.h"

using namespace std;

int main() {
    LeetCode81 leetCode81;
    vector<int> arr = {1};
    cout << leetCode81.search(arr, 1) << endl;

    LeetCode59 leetCode59;
    leetCode59.generateMatrix(3);

    LeetCode80 leetCode80;
    arr = {1,1,1,2};
    cout << leetCode80.removeDuplicates(arr) << endl;

    LeetCode1552 leetCode1552;
    arr = {1,2,3,4,7};
    cout << leetCode1552.maxDistance(arr, 3) << endl;

//#pragma pack(1)
    struct Demo {
        char c1: 3;
        short s1: 2;
        char c2: 5;
    };
//#pragma pack()
    cout << sizeof(Demo) << endl;
    Demo demo;
    demo.c1 = '1';
    demo.s1 = 5;
    cout << demo.s1 << endl;

    arr = {8,4,2,5,4,5,8,6,2,3};
    RangeFreqQuery rangeFreqQuery(arr);
    cout << rangeFreqQuery.query(4, 5, 1) << endl;
//    cout << rangeFreqQuery.query(0, 11, 33) << endl;

    union {
        int iVal;
        char cVal;
        double dVal;
    };
    cVal = 'c';
    cout << iVal << " " << cVal << " " << dVal << endl;
    printf("%c, %c, %c", iVal, cVal, dVal);

    LeetCode3306 leetCode3306;
    cout << leetCode3306.countOfSubstrings("aeiou", 0) << endl;

    LeetCode2680 leetCode2680;
    arr = {12, 9};
    cout << leetCode2680.maximumOr(arr, 1) << endl;

    LeetCode2116 leetCode2116;
    cout << leetCode2116.canBeValid("))()))", "010100") << endl;

    LeetCode1863 leetCode1863;
    arr = {1, 3};
    cout << leetCode1863.subsetXORSum(arr) << endl;

    LeetCode3396 leetCode3396;
    arr = {1,2,3,4,2,3,3,5,7};
    cout << leetCode3396.minimumOperations(arr) << endl;

    LeetCode1534 leetCode1534;
    arr = {3,0,1,1,9,7};
    cout << leetCode1534.countGoodTriplets(arr, 7, 2, 3) << endl;

    LeetCode2537 leetCode2537;
    arr = {1, 1, 1, 1, 1};
    cout << leetCode2537.countGood(arr, 10) << endl;

    LeetCode2563 leetCode2563;
    arr = {0,0,0,0,0,0};
    cout << leetCode2563.countFairPairs(arr, 0, 0) << endl;

    LeetCode2799 leetCode2799;
    arr = {459,459,962,1579,1435,756,1872,1597};
    cout << leetCode2799.countCompleteSubarrays(arr) << endl;
    return 0;
}
