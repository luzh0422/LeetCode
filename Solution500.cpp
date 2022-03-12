//
// Created by luzh on 2021/10/31.
//

#include "Solution500.h"
#include <unordered_map>

vector<string> Solution500::findWords(vector<string> &words) {
    unordered_map<char, int> uM;
    uM['q'] = 0;
    uM['w'] = 0;
    uM['e'] = 0;
    uM['r'] = 0;
    uM['t'] = 0;
    uM['y'] = 0;
    uM['u'] = 0;
    uM['i'] = 0;
    uM['o'] = 0;
    uM['p'] = 0;
    uM['a'] = 1;
    uM['s'] = 1;
    uM['d'] = 1;
    uM['f'] = 1;
    uM['g'] = 1;
    uM['h'] = 1;
    uM['j'] = 1;
    uM['k'] = 1;
    uM['l'] = 1;
    uM['z'] = 2;
    uM['x'] = 2;
    uM['c'] = 2;
    uM['v'] = 2;
    uM['b'] = 2;
    uM['n'] = 2;
    uM['m'] = 2;
    int curr = -1;
    vector<string> ans;
    for (auto& word: words) {
        if (word == "") {
            continue;
        }
        curr = uM[toLower(word[0])];
        int index = 1;
        for (; index < word.size(); index++) {
            if (uM[toLower(word[index])] != curr) {
                break;
            }
        }
        if (index == word.size()) {
            ans.push_back(word);
        }
    }
    return ans;
}

char Solution500::toLower(char c) {
    switch (c) {
        case 'A':
            return 'a';
        case 'B':
            return 'b';
        case 'C':
            return 'c';
        case 'D':
            return 'd';
        case 'E':
            return 'e';
        case 'F':
            return 'f';
        case 'G':
            return 'g';
        case 'H':
            return 'h';
        case 'I':
            return 'i';
        case 'J':
            return 'j';
        case 'K':
            return 'k';
        case 'L':
            return 'l';
        case 'M':
            return 'm';
        case 'N':
            return 'n';
        case 'O':
            return 'o';
        case 'P':
            return 'p';
        case 'Q':
            return 'q';
        case 'R':
            return 'r';
        case 'S':
            return 's';
        case 'T':
            return 't';
        case 'U':
            return 'u';
        case 'V':
            return 'v';
        case 'W':
            return 'w';
        case 'X':
            return 'x';
        case 'Y':
            return 'y';
        case 'Z':
            return 'z';
    }
    return c;
}
