#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "LeetCode2831.h"
#include "LeetCode1673.h"
#include "LeetCode3067.h"
#include "LeetCode2786.h"
#include "LeetCode2970.h"
#include "LeetCode3011.h"
#include "LeetCode2850.h"
#include "LeetCode3128.h"
#include "LeetCode3143.h"
#include "LeetCode1035.h"
#include "LeetCode3152.h"
#include "LeetCode3137.h"
#include "LeetCode3133.h"
#include "LeetCode3144.h"
#include "LeetCode2332.h"
#include "LeetCode2708.h"
#include "LeetCode2207.h"
#include "LeetCode2516.h"
#include "LeetCode983.h"
#include "LeetCode1870.h"
#include "LeetCode2187.h"
#include "LeetCode134.h"
#include "LeetCode3164.h"
#include "LeetCode3192.h"
#include "LeetCode3216.h"
#include "LeetCode633.h"
#include "LeetCode3254.h"
#include "LeetCode3255.h"
#include "LeetCode3258.h"
#include "LeetCode3249.h"

using namespace std;

int main() {
    vector<int> nums = {1, 2, 1};
    LeetCode2831 leetCode2831;
    cout << leetCode2831.longestEqualSubarray(nums, 3) << endl;

    LeetCode1673 leetCode1673;
    nums = {3, 5, 2, 6};
    leetCode1673.mostCompetitive(nums, 2);

    LeetCode3067 leetCode3067;
    vector<vector<int>> edges = {{0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2}};
    leetCode3067.countPairsOfConnectableServers(edges, 1);

    LeetCode2786 leetCode2786;
    vector<int> arr = {9,58,17,54,91,90,32,6,13,67,24,80,8,56,29,66,85,38,45,13,20,73,16,98,28,56,23,2,47,85,11,97,72,2,28,52,33};
    cout << leetCode2786.maxScore(arr, 90) << endl;

    LeetCode2970 leetCode2970;
    arr = {1, 2, 3, 4};
    cout << leetCode2970.incremovableSubarrayCount(arr) << endl;

    LeetCode3011 leetCode3011;
    arr = {8,4,2,30,15};
    cout << leetCode3011.canSortArray(arr) << endl;

    LeetCode2850 leetCode2850;
    vector<vector<int>> arrarr = {{1,2,2},{1,1,0},{0,1,1}};
    cout << leetCode2850.minimumMoves(arrarr) << endl;

    LeetCode3128 leetCode3128;
    arrarr = {{1,0,0,0},{0,1,0,1},{1,0,0,0}};
    cout << leetCode3128.numberOfRightTriangles(arrarr) << endl;

    LeetCode3143 leetCode3143;
    arrarr = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
    string temp = "abdca";
    cout << leetCode3143.maxPointsInsideSquare(arrarr, temp) << endl;

    LeetCode1035 leetCode1035;
    vector<int> arr1 = {2,5,1,2,5};
    vector<int> arr2 = {10,5,2,1,5,2};
    cout << leetCode1035.maxUncrossedLines(arr1, arr2) << endl;

    LeetCode3152 leetCode3152;
    arr = {4, 3, 1, 6};
    arrarr = {{0, 2}, {2, 3}};
    leetCode3152.isArraySpecial(arr, arrarr);

    LeetCode3137 leetCode3137;
    cout << leetCode3137.minimumOperationsToMakeKPeriodic("leetcoleet", 2) << endl;

    LeetCode3133 leetCode3133;
    cout << leetCode3133.minEnd(3, 4) << endl;

    LeetCode3144 leetCode3144;
    cout << leetCode3144.minimumSubstringsInPartition("abababaccddb") << endl;

    LeetCode2332 leetCode2332;
    arr1 = {10, 20};
    arr2 = {2, 17, 18, 19};
    cout << leetCode2332.latestTimeCatchTheBus(arr1, arr2, 1) << endl;

    LeetCode2708 leetCode2708;
    arr = {6,-3,-4,8,4,7,6,4,7,7,-3,-6,9};
    cout << leetCode2708.maxStrength(arr) << endl;

    LeetCode2207 leetCode2207;
    cout << leetCode2207.maximumSubsequenceCount("ccccc", "cc");

    LeetCode2516 leetCode2516;
    leetCode2516.takeCharacters("aabaaaacaabc", 2);

    LeetCode983 leetCode983;
    arr1 = {1,4,6,7,8,20};
    arr2 = {2,7,15};
    cout << leetCode983.mincostTickets(arr1, arr2) << endl;

    LeetCode1870 leetCode1870;
    arr1 = {1, 3, 2};
    cout << leetCode1870.minSpeedOnTime(arr1, 2.7) << endl;

    LeetCode134 leetCode134;
    arr1 = {1,2,3,4,5};
    arr2 = {3,4,5,1,2};
    cout << leetCode134.canCompleteCircuit(arr1, arr2) << endl;

    LeetCode3164 leetCode3164;
    arr1 = {1, 2, 4, 12};
    arr2 = {2, 4};
    cout << leetCode3164.numberOfPairs(arr1, arr2, 3) << endl;

    LeetCode3192 leetCode3192;
    arr = {1, 0, 0, 0};
    cout << leetCode3192.minOperations(arr) << endl;

    LeetCode3216 leetCode3216;
    cout << leetCode3216.getSmallestString("45320") << endl;

    LeetCode633 leetCode633;
    cout << leetCode633.judgeSquareSum(2) << endl;

    LeetCode3254 leetCode3254;
    arr = {1,2,3,4,3,2,5};
    leetCode3254.resultsArray(arr, 3);

    LeetCode3255 leetCode3255;
    leetCode3255.resultsArray(arr, 3);

    LeetCode3258 leetCode3258;
    cout << leetCode3258.countKConstraintSubstrings("10101", 1) << endl;

    LeetCode3249 leetCode3249;
    arrarr = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    cout << leetCode3249.countGoodNodes(arrarr) << endl;
    return 0;
}
