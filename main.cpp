#include <iostream>
#include "Solution.h"
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include "Solution92.h"
#include "Solution150.h"
#include "Solution73.h"
#include "Solution341.h"
#include "Solution508.h"
#include "Solution74.h"
#include "Solution1006.h"
#include "Solution781.h"
#include "Solution80.h"
#include "Solution783.h"
//#include "Solution208.h"
#include "Solution213.h"
#include "Solution91.h"
#include "Solution897.h"
#include "Solution1011.h"
#include "Solution137.h"
#include "Solution1734.h"
#include "Solution1269.h"
#include "Solution1442.h"
#include "Solution1738.h"
#include "Solution1035.h"
#include "Solution231_2.h"
#include "Solution1744.h"
#include "Solution523.h"
#include "Solution525.h"
#include "Solution494.h"
#include "Solution485.h"
#include "Solution278.h"
#include "Solution852.h"
#include "Solution877.h"
#include "Solution65.h"
#include "Solution1239.h"
#include "Solution168.h"
#include "Solution451.h"
#include "Solution645.h"
#include "Solution726.h"
#include "Solution1418.h"
#include "Solution1711.h"
#include "Solution981.h"
#include "Solution1818.h"
#include "Solution1743.h"
#include "Solution671.h"
#include "Solution1104.h"
#include "Solution171.h"
#include "Solution1833.h"
#include "Solution1337.h"
#include "Solution743.h"
#include "Solution581.h"
#include "Solution611.h"
#include "Solution802.h"
#include "Solution457.h"
#include "Solution516.h"
#include "Solution576.h"
#include "Solution526.h"
#include "Solution551.h"
#include "Solution345.h"
#include "Solution787.h"
#include "Solution295.h"
#include "Solution1588.h"
#include "Solution528.h"
#include "SolutionMian17_14.h"
#include "Solution470.h"
#include "Solution1221.h"
#include "Solution68.h"
#include "Solution1894.h"
#include "Solution678.h"
#include "Solution447.h"
#include "Solution524.h"
#include "Solution162.h"
#include "Solution36.h"
#include "Solution58.h"
#include "Solution430.h"
#include "Solution583.h"
#include "Solution371.h"
#include "Solution437.h"
#include "Solution482.h"
#include "Solution414.h"
#include "Solution187.h"
#include "Solution352.h"
#include "Solution441.h"
#include "Solution273.h"
#include "SolutionOffer069.h"
#include "Solution38.h"
#include "Solution476.h"
#include "HUAWEI0.h"
#include "HUAWEI2.h"
#include "HUAWEI3.h"
#include "HUAWEI4.h"
#include "Solution869.h"
#include "Solution500.h"
#include "Solution375.h"
#include "Solution520.h"
#include "Solution319.h"
#include "Solution391.h"
#include "Solution318.h"
#include "Solution563.h"
#include "Solution397.h"
#include "Solution559.h"
#include "Solution384.h"
#include "Solution458.h"
#include "Solution483.h"
#include "Solution400.h"
#include "Solution506.h"
#include "Solution1816.h"
#include "Solution1034.h"
#include "Solution911.h"
#include "Solution709.h"
#include "Solution630.h"
#include "Solution851.h"
#include "Solution1154.h"
#include "Solution1705.h"
#include "Solution825.h"
#include "Solution472.h"
#include "Solution846.h"
#include "Solution2022.h"
#include "Solution89.h"
#include "Solution306.h"
#include "Solution28.h"
#include "Solution1716.h"
#include "Solution378.h"
#include "Solution539.h"
#include "Solution1345.h"
#include "Solution1688.h"
#include "Solution2047.h"
#include "Solution1765.h"
#include "Solution1763.h"
#include "Solution1405.h"
#include "Solution1001.h"
#include "Solution1984.h"
#include "Solution1020.h"
#include "Solution540.h"
#include "Solution688.h"
#include "Solution917.h"
#include "Solution1706.h"
#include "Solution2100.h"
#include "Solution2055.h"
#include "LeetCode798.h"
#include "LeetCode2049.h"

using namespace std;


vector<int> stringToNums(string s) {
    int curr = 0;
    vector<int> ans = {};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] ==',') {
            ans.push_back(curr);
            curr = 0;
        } else {
            curr = curr * 10 + (s[i] - '0');
        }
    }
    if (curr != 0) {
        ans.push_back(curr);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl;
    cout << myHashMap.get(3) << endl;
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl;
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl;
    vector<int> arr = {1, 2, 3, 4};
    vector<vector<int>> arrarr = {};
    arrarr.push_back(arr);
    arr = {5, 6, 7, 8};
    arrarr.push_back(arr);
    arr = {9, 10, 11, 12};
    arrarr.push_back(arr);
    Solution solution;
    solution.spiralOrder(arrarr);

    /**
     * Solution92,利用stack处理数据；
     */
    Solution92 solution92;
    ListNode* listNode = new ListNode(1);
    listNode->next = new ListNode(2);
    listNode->next->next = new ListNode(3);
    listNode->next->next->next = new ListNode(4);
    listNode->next->next->next->next = new ListNode(5);
    solution92.reverseBetween(listNode, 2, 4);

    /**
     * Solution150, 利用stack处理数据计算；
     */
    Solution150 solution150;
    vector<string> strs = {"4","13","5","/","+"};
    cout << solution150.evalRPN(strs) << endl;

    /**
     * Solution73, 利用pair储存数据；
     */
    arrarr = {};
    arr = {0,1,2,0};
    arrarr.push_back(arr);
    arr = {3,4,5,2};
    arrarr.push_back(arr);
    arr = {1,3,1,5};
    arrarr.push_back(arr);
    Solution73 solution73;
    solution73.setZeroes(arrarr);

    /**
     * Solution341，递归遍历；
     */
    NestedInteger nestedInteger;
    NestedInteger nestedInteger1(1);
    NestedInteger nestedInteger2(2);
    NestedInteger nestedInteger3(3);
    NestedInteger nestedInteger4(4);
    vector<NestedInteger> nestedIntegers;
    nestedIntegers.push_back(nestedInteger3);
    nestedIntegers.push_back(nestedInteger4);
    NestedInteger nestedInteger5(nestedIntegers);
    vector<NestedInteger> nestedIntegers2;
    nestedIntegers2.push_back(nestedInteger);
//    nestedIntegers2.push_back(nestedInteger1);
//    nestedIntegers2.push_back(nestedInteger2);
//    nestedIntegers2.push_back(nestedInteger5);
    NestedIterator nestedIterator(nestedIntegers2);
    while (nestedIterator.hasNext()) {
        cout << nestedIterator.next() << " ";
    }
    cout << endl;
    Solution508 solution508;
    cout << solution508.reverseBits(43261596) << endl;

    Solution74 solution74;
    arrarr = {};
    arr = {1};
    arrarr.push_back(arr);
    cout << solution74.searchMatrix(arrarr, 1) << endl;

    Solution1006 solution1006;
    cout <<  solution1006.clumsy(10) << endl;

    Solution781 solution781;
    arr = {2,0,0,2,1,1,0,0,2,0};
    cout << solution781.numRabbits(arr) << endl;

    Solution80 solution80;
    arr = {1,1,1,2,2,2,3,3};
    cout << solution80.removeDuplicates(arr) << endl;

    Solution783 solution783;
    TreeNode* root = new TreeNode(90);
    root->left = new TreeNode(69);
    root->left->left = new TreeNode(49);
    root->left->right = new TreeNode(89);
    root->left->left->right = new TreeNode(52);
    cout << solution783.minDiffInBST(root) << endl;


//    Trie trie;
//    trie.insert("apple");
//    cout << trie.search("apple") << endl;

    Solution213 solution213;
    arr = {1, 2, 3, 1};
    cout << solution213.rob(arr) << endl;

    Solution91 solution91;
    cout << solution91.numDecodings("226") << endl;

    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    Solution897 solution897;
    solution897.increasingBST(root);

    Solution1011 solution1011;
    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solution1011.shipWithinDays(arr, 5) << endl;

    Solution137 solution137;
    arr = {2, 2, 3, 2};
    cout << solution137.singleNumber(arr) << endl;

    Solution1734 solution1734;
    arr = {3, 1};
    solution1734.decode(arr);

    Solution1269 solution1269;
    solution1269.numWays(2, 4);

    Solution1442 solution1442;
    arr = {2, 3, 1, 6, 7};
    cout << solution1442.countTriplets(arr) << endl;

    Solution1738 solution1738;
    arrarr = {};
    arr = {5, 2};
    arrarr.push_back(arr);
    arr = {1, 6};
    arrarr.push_back(arr);
    cout << solution1738.kthLargestValue(arrarr, 1) << endl;

    Solution1035 solution1035;
    vector<int> arr1 = {3};
    vector<int> arr2 = {3, 3, 2};
    cout << solution1035.maxUncrossedLines(arr1, arr2) << endl;

    Solution231_2 solution231_2;
    cout << solution231_2.isPowerOfTwo(16) << endl;

    Solution1744 solution1744;
    vector<int> candiesCount = {7, 4, 5, 3, 8};
    vector<vector<int>> queries = {};
    vector<int> query = {0, 2, 2};
    queries.push_back(query);
    query = {4, 2, 4};
    queries.push_back(query);
    query = {2,13,1000000000};
    queries.push_back(query);
    solution1744.canEat(candiesCount, queries);


    Solution523 solution523;
    arr = {1, 2, 3};
    cout << solution523.checkSubarraySum(arr, 5) << endl;


    Solution525 solution525;
    arr = {0, 0, 0, 1, 1};
    cout << solution525.findMaxLength(arr) << endl;

    Solution494 solution494;
    arr = {1, 1, 1, 1, 1};
    cout << solution494.findTargetSumWays(arr, 3) << endl;

    Solution485 solution485;
    arr = {1, 2, 5};
    cout << solution485.change(5, arr) << endl;


    Solution278 solution278;
    cout << solution278.firstBadVersion(6) << endl;

    Solution852 solution852;
    arr = {0, 1, 0};
    cout << solution852.peakIndexInMountainArray(arr) << endl;

    Solution877 solution877;
    arr = {5, 3, 4, 5};
    cout << solution877.stoneGame(arr) << endl;

    Solution65 solution65;
    cout << solution65.isNumber("123") << endl;

    Solution1239 solution1239;
    strs = {"un", "iq", "ue"};
    cout << solution1239.maxLength(strs) << endl;

    Solution168 solution168;
    cout << solution168.convertToTitle(52) << endl;

//    SolutionOffer37 solutionOffer37;
//    TreeNode* solutionOffer37Root = solutionOffer37.deserialize("1,2,3,null,null,4,5");
//    cout << solutionOffer37.serialize(solutionOffer37Root) << endl;

    Solution451 solution451;
    cout << solution451.frequencySort("tree") << endl;

    Solution645 solution645;
    arr = {1, 2, 2, 4};
    solution645.findErrorNums(arr);

    Solution726 solution726;
    cout << solution726.countOfAtoms("Mg(OH)2") << endl;

    Solution1418 solution1418;
    vector<vector<string>> orders = {};
    vector<string> order = {"David","3","Ceviche"};
    orders.push_back(order);
    order = {"Corina","10","Beef Burrito"};
    orders.push_back(order);
    order = {"David","3","Fried Chicken"};
    orders.push_back(order);
    order = {"Carla","5","Water"};
    orders.push_back(order);
    order = {"Carla","5","Ceviche"};
    orders.push_back(order);
    order = {"Rous","3","Ceviche"};
    orders.push_back(order);
    solution1418.displayTable(orders);

    Solution1711 solution1711;
    arr = {1, 3, 5, 7, 9};
    cout << solution1711.countPairs(arr) << endl;

    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    cout << timeMap.get("foo", 3) << endl;
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 5) << endl;

    arr1 = {1, 7, 5};
    arr2 = {2, 3, 5};
    Solution1818 solution1818;
    cout << solution1818.minAbsoluteSumDiff(arr1, arr2) << endl;

    arrarr = {};
    arr = {4, -10};
    arrarr.push_back(arr);
    arr = {-1, 3};
    arrarr.push_back(arr);
    arr = {4, -3};
    arrarr.push_back(arr);
    arr = {-3, 3};
    arrarr.push_back(arr);
    Solution1743 solution1743;
    solution1743.restoreArray(arrarr);

    root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(1);
    root->left->left->left->left = new TreeNode(3);
    root->left->left->left->right = new TreeNode(3);
    root->left->left->right->left = new TreeNode(1);
    root->left->left->right->right = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(1);
    root->left->right->left->left = new TreeNode(2);
    root->left->right->left->right = new TreeNode(1);
    Solution671 solution671;
    cout << solution671.findSecondMinimumValue(root) << endl;

    Solution1104 solution1104;
    solution1104.pathInZigZagTree(14);

    Solution171 solution171;
    cout << solution171.titleToNumber("AB") << endl;

    arr = {1, 3, 2, 4, 1};
    Solution1833 solution1833;
    cout << solution1833.maxIceCream(arr, 7) << endl;

    arrarr = {};
//    arr = {1, 1, 0, 0, 0};
//    arrarr.push_back(arr);
//    arr = {1, 1, 1, 1, 0};
//    arrarr.push_back(arr);
//    arr = {1, 0, 0, 0, 0};
//    arrarr.push_back(arr);
//    arr = {1, 1, 0, 0, 0};
//    arrarr.push_back(arr);
    arr = {1, 1, 1, 1, 1, 1};
    arrarr.push_back(arr);
    Solution1337 solution1337;
    solution1337.kWeakestRows(arrarr, 1);

    arrarr = {};
    arr = {2, 1, 1};
    arrarr.push_back(arr);
    arr = {2, 3, 1};
    arrarr.push_back(arr);
    arr = {3, 4, 1};
    arrarr.push_back(arr);
    Solution743 solution743;
    cout << solution743.networkDelayTime(arrarr, 4, 2) << endl;

    Solution581 solution581;
    arr = {2, 6, 4, 8, 10, 9, 15};
    cout << solution581.findUnsortedSubarray(arr) << endl;

    Solution611 solution611;
    arr = {2, 2, 3, 4};
    cout << solution611.triangleNumber(arr) << endl;

    arrarr = {};
    arr = {};
    arrarr.push_back(arr);
    arr = {0, 2, 3, 4};
    arrarr.push_back(arr);
    arr = {3};
    arrarr.push_back(arr);
    arr = {4};
    arrarr.push_back(arr);
    arr = {};
    arrarr.push_back(arr);
//    arr = {};
//    arrarr.push_back(arr);
//    arr = {};
//    arrarr.push_back(arr);
    Solution802 solution802;
    solution802.eventualSafeNodes(arrarr);

    Solution457 solution457;
    arr = {1,1,2};
    cout << solution457.circularArrayLoop(arr) << endl;

    Solution516 solution516;
    cout << solution516.longestPalindromeSubseq("bbbab") << endl;

    Solution576 solution576;
    cout << solution576.findPaths(1, 3, 3, 0, 1) << endl;

    Solution526 solution526;
    cout << solution526.countArrangement(2) << endl;

    Solution551 solution551;
    cout << solution551.checkRecord("APPLLL") << endl;

    Solution345 solution345;
    cout << solution345.reverseVowels("hello") << endl;

    Solution787 solution787;
    arrarr = {};
    arr = {0, 1, 100};
    arrarr.push_back(arr);
    arr = {1, 2, 100};
    arrarr.push_back(arr);
    arr = {0, 2, 500};
    arrarr.push_back(arr);
    cout << solution787.findCheapestPrice(3, arrarr, 0, 2, 1) << endl;

    MedianFinder medianFinder;
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(-1);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(-2);
    cout << medianFinder.findMedian() << endl;

    Solution1588 solution1588;
    arr = {1, 4, 2, 5, 3};
    cout << solution1588.sumOddLengthSubarrays(arr) << endl;

    arr = {1};
    Solution528 solution528(arr);
    cout << solution528.pickIndex() << endl;
    cout << solution528.pickIndex() << endl;
    cout << solution528.pickIndex() << endl;
    cout << solution528.pickIndex() << endl;


    SolutionMian17_14 solutionMian1714;
    arr = {1,3,5,7,2,4,6,8};
    solutionMian1714.smallestK(arr, 4);

    Solution470 solution470;
    cout << solution470.rand10() << endl;
    cout << solution470.rand10() << endl;
    cout << solution470.rand10() << endl;

    Solution1221 solution1221;
    cout << solution1221.balancedStringSplit("RLRRLLRLRL") << endl;

    Solution68 solution68;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    solution68.fullJustify(words, 16);

    Solution1894 solution1894;
    arr = {3, 4, 1, 2};
    cout << solution1894.chalkReplacer(arr, 25) << endl;

    Solution678 solution678;
    cout << solution678.checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())") << endl;

    Solution447 solution447;
    arrarr = {};
    arr = {0, 0};
    arrarr.push_back(arr);
    arr = {1, 0};
    arrarr.push_back(arr);
    arr = {-1, 0};
    arrarr.push_back(arr);
    arr = {0, 1};
    arrarr.push_back(arr);
    arr = {0, -1};
    arrarr.push_back(arr);
    cout << solution447.numberOfBoomerangs(arrarr) << endl;

    Solution524 solution524;
    strs = {"ale","apple","monkey","plea"};
    cout << solution524.findLongestWord("abpcplea", strs) << endl;

    Solution162 solution162;
    arr = {1, 2, 3, 1};
    cout << solution162.findPeakElement(arr) << endl;

    Solution36 solution36;
    vector<vector<char>> board = {{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};
    cout << solution36.isValidSudoku(board) << endl;

    Solution58 solution58;
    cout << solution58.lengthOfLastWord("Hello World") << endl;

    Node* node = new Node();
    node->val = 1;
    node->next = new Node();
    node->next->val  = 2;
    node->next->next = new Node();
    node->next->next->val = 3;
    node->next->next->child = new Node();
    node->next->next->child->val = 7;
    node->next->next->next = new Node();
    node->next->next->next->val = 4;
    Solution430 solution430;
    solution430.flatten(node);

    Solution583 solution583;
    cout << solution583.minDistance("a", "b") << endl;

    Solution371 solution371;
    cout << solution371.getSum(1, -1) << endl;

    Solution437 solution437;
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    cout << solution437.pathSum(root, 8) << endl;

    Solution482 solution482;
    cout << solution482.licenseKeyFormatting("2", 2) << endl;

    Solution414 solution414;
    arr = {3, 2, 1};
    cout << solution414.thirdMax(arr) << endl;

    Solution187 solution187;
    solution187.findRepeatedDnaSequences("AAAAAAAAAAAAA");

    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);
    summaryRanges.getIntervals();
    summaryRanges.addNum(0);
    summaryRanges.getIntervals();


    Solution441 solution441;
    cout << solution441.arrangeCoins(5) << endl;

    Solution273 solution273;
    cout << solution273.numberToWords(1234567891) << endl;

    SolutionOffer069 solutionOffer069;
    arr = {3, 5, 3, 2, 0};
    cout << solutionOffer069.peakIndexInMountainArray(arr) << endl;

    Solution38 solution38;
    cout << solution38.countAndSay(4) << endl;

    Solution476 solution476;
    cout << solution476.findComplement(1) << endl;

    HUAWEI2 huawei2;
    cout << huawei2.sortString("cAbadD") << endl;

    arr = {24,5,50,30,31,30,33,37};
    HUAWEI3 huawei3;
    cout << huawei3.shortestNum(arr) << endl;

    stringToNums("24,5,50,30,31,30,33,37");

    Solution869 solution869;
    cout << solution869.reorderedPowerOf2(10) << endl;

    Solution500 solution500;
    strs = {"Hello","Alaska","Dad","Peace"};
    solution500.findWords(strs);

    Solution375 solution375;
    cout << solution375.getMoneyAmount(10) << endl;

    Solution520 solution520;
    cout << solution520.detectCapitalUse("mL") << endl;

    Solution319 solution319;
    cout << solution319.bulbSwitch(5) << endl;

    arrarr = {};
    arr = {1, 1, 3, 3};
    arrarr.push_back(arr);
    arr = {3, 1, 4, 2};
    arrarr.push_back(arr);
    arr = {3, 2, 4, 4};
    arrarr.push_back(arr);
    arr = {1, 3, 2, 4};
    arrarr.push_back(arr);
    arr = {2, 3, 3, 4};
    arrarr.push_back(arr);
    Solution391 solution391;
    cout << solution391.isRectangleCover(arrarr) << endl;

    Solution318 solution318;
    strs = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << solution318.maxProduct(strs) << endl;

    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    Solution563 solution563;
    cout << solution563.findTilt(root) << endl;

    Solution397 solution397;
    cout << solution397.integerReplacement(7) << endl;

    MultiNodes::Node* multiRoot = new MultiNodes::Node(1);
    MultiNodes::Node* multiNode = new MultiNodes::Node(3);
    multiRoot->children.push_back(multiNode);
    multiNode = new MultiNodes::Node(2);
    multiRoot->children.push_back(multiNode);
    multiNode = new MultiNodes::Node(4);
    multiRoot->children.push_back(multiNode);
    multiNode = new MultiNodes::Node(5);
    multiRoot->children[0]->children.push_back(multiNode);
    multiNode = new MultiNodes::Node(6);
    multiRoot->children[0]->children.push_back(multiNode);

    MultiNodes::Solution559 solution559;
    cout << solution559.maxDepth(multiRoot) << endl;

    arr = {1, 2, 3};
    Solution384 solution384(arr);
    solution384.shuffle();
    solution384.reset();

//    Solution859 solution859;
//    cout << solution859.buddyStrings("aa", "aa") << endl;

    Solution458 solution458;
    cout << solution458.poorPigs(4, 15, 15) << endl;

    Solution483 solution483;
//    solution483.findAnagrams("abab", "ab");
    solution483.findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa");

    Solution400 solution400;
    cout << solution400.findNthDigit(9) << endl;
    cout << solution400.findNthDigit(10) << endl;
    cout << solution400.findNthDigit(11) << endl;
    cout << solution400.findNthDigit(12) << endl;
    cout << solution400.findNthDigit(13) << endl;

    Solution506 solution506;
    arr = {5, 4, 3, 2, 1};
    solution506.findRelativeRanks(arr);

    Solution1816 solution1816;
    cout << solution1816.truncateSentence("chopper is not a tanuki", 5) << endl;

    Solution1034 solution1034;
    arrarr = {};
    arr = {1, 1};
    arrarr.push_back(arr);
    arr = {1, 2};
    arrarr.push_back(arr);
    solution1034.colorBorder(arrarr, 0, 0, 3);

    vector<int> persons = {0, 0, 1, 1, 2};
    vector<int> times = {0, 67, 69, 74, 87};
    TopVotedCandidate topVotedCandidate(persons, times);
    cout << topVotedCandidate.q(100) << endl;

    Solution709 solution709;
    cout << solution709.toLowerCase("Hello") << endl;

    Solution630 solution630;
    arrarr = { {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200} };
    cout << solution630.scheduleCourse(arrarr) << endl;

    Solution851 solution851;
    arrarr = { {1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3} };
    arr = {3, 2, 5, 4, 6, 1, 7, 0};
    solution851.loudAndRich(arrarr, arr);

    Solution1154 solution1154;
    cout << solution1154.dayOfYear("2004-03-01") << endl;

    Solution1705 solution1705;
    vector<int> apples = {1, 2, 3, 5, 2};
    vector<int> days = {3, 2, 1, 4, 2};
    cout << solution1705.eatenApples(apples, days) << endl;

    HUAWEI0 huawei0;
    cout << huawei0.longestNoRepeat("abcabcbb") << endl;
    cout << huawei0.longestNoRepeat("bbbbb") << endl;
    cout << huawei0.longestNoRepeat("pwwkew") << endl;
    cout << huawei0.longestNoRepeat("") << endl;

    Solution825 solution825;
    arr = {20, 30, 100, 110, 120};
    cout << solution825.numFriendRequests(arr) << endl;

    Solution472 solution472;
    words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    solution472.findAllConcatenatedWordsInADict(words);

    Solution846 solution846;
    arr = {1,2,3,6,2,3,4,7,8};
    cout << solution846.isNStraightHand(arr, 3) << endl;

    Solution2022 solution2022;
    arr = {1, 2, 3, 4};
    solution2022.construct2DArray(arr, 2, 2);

    Solution89 solution89;
    solution89.grayCode(2);

    Solution306 solution306;
    cout << solution306.isAdditiveNumber("198019823962") << endl;

    HUAWEI4 huawei4;
    arr = {-2,1,-3,4,-1,2,1,-5,4};
    huawei4.theMaxSubsequence(arr);

    Solution28 solution28;
    cout << solution28.strStr("abeababeabf", "abeabf") << endl;

    Solution1716 solution1716;
    cout << solution1716.totalMoney(10) << endl;

    Solution378 solution378;
    arrarr = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << solution378.kthSmallest(arrarr, 8) << endl;

    Solution539 solution539;
    strs = {"00:00", "04:00", "22:00"};
    cout << solution539.findMinDifference(strs) << endl;

    Solution1345 solution1345;
    arr = {25,-28,-51,61,-74,-51,-30,58,36,68,-80,-64,25,-30,-53,36,-74,61,-100,-30,-52};
    cout << solution1345.minJumps(arr) << endl;

    Solution1688 solution1688;
    cout << solution1688.numberOfMatches(7) << endl;

    Solution2047 solution2047;
    cout << solution2047.countValidWords(" 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e 9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif ") << endl;

    Solution1765 solution1765;
    arrarr = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    solution1765.highestPeak(arrarr);

    Solution1763 solution1763;
    cout << solution1763.longestNiceSubstring("dDzeE") << endl;

    Solution1405 solution1405;
    cout << solution1405.longestDiverseString(7, 1, 0) << endl;

    Solution1001 solution1001;
    vector<vector<int>> lamps = {{2, 5}, {4, 2}, {0, 3}, {0, 5}, {1, 4}, {4, 2}, {3, 3}, {1, 0}};
    vector<vector<int>> queries2 = {{4, 3}, {3, 1}, {5, 3}, {0, 5}, {4, 4}, {3, 3}};
    solution1001.gridIllumination(6, lamps, queries2);

    Solution1984 solution1984;
    arr = {90};
    cout << solution1984.minimumDifference(arr, 1) << endl;

    Solution1020 solution1020;
    arrarr = {{0,0,0,1,1,1,0,1,1,1,1,1,0,0,0},
              {1,1,1,1,0,0,0,1,1,0,0,0,1,1,1},
              {1,1,1,0,0,1,0,1,1,1,0,0,0,1,1},
              {1,1,0,1,0,1,1,0,0,0,1,1,0,1,0},
              {1,1,1,1,0,0,0,1,1,1,0,0,0,1,1},
              {1,0,1,1,0,0,1,1,1,1,1,1,0,0,0},
              {0,1,0,0,1,1,1,1,0,0,1,1,1,0,0},
              {0,0,1,0,0,0,0,1,1,0,0,1,0,0,0},
              {1,0,1,0,0,1,0,0,0,0,0,0,1,0,1},
              {1,1,1,0,1,0,1,0,1,1,1,0,0,1,0}};
    cout << solution1020.numEnclaves(arrarr) << endl;

    Solution540 solution540;
    arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << solution540.singleNonDuplicate(arr) << endl;

    Solution688 solution688;
    cout << solution688.knightProbability(3, 2, 0, 0) << endl;

    Solution917 solution917;
    cout << solution917.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;

    Solution1706 solution1706;
    arrarr = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    solution1706.findBall(arrarr);

    Solution2100 solution2100;
    arr = {5, 3, 3, 3, 5, 6, 2};
    solution2100.goodDaysToRobBank(arr, 0);

    Solution2055 solution2055;
//    string s = "***|**|*****|**||**|*";
    string s = "**|**|***|";
    arrarr = {{2, 5}, {5, 9}};
    solution2055.platesBetweenCandles(s, arrarr);

    LeetCode798 leetCode798;
    arr = {1, 3, 0, 2, 4};
    cout << leetCode798.bestRotation(arr) << endl;

    LeetCode2049 leetCode2049;
    arr = {-1, 2, 0, 2, 0};
    cout << leetCode2049.countHighestScoreNodes(arr) << endl;
    return 0;
}
