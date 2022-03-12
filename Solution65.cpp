//
// Created by luzh on 2021/6/17.
//

#include "Solution65.h"
#include <unordered_map>

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

Solution65::CharType Solution65::toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
        return CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
        return CHAR_EXP;
    } else if (ch == '.') {
        return CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
        return CHAR_SIGN;
    } else {
        return CHAR_ILLEGAL;
    }
}

bool Solution65::isNumber(string s) {
    /**
     * <当前的状态值，<输入值， 根据输入值转换后的状态值 >>
     */
    unordered_map<State, unordered_map<CharType, State, EnumClassHash>, EnumClassHash> transfer {
        {
            STATE_INITIAL, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                {CHAR_SIGN, STATE_INT_SIGN}
            }
        }, {
            STATE_INT_SIGN, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
            }
        }, {
           STATE_INTEGER, {
               {CHAR_NUMBER, STATE_INTEGER},
               {CHAR_EXP, STATE_EXP},
               {CHAR_POINT, STATE_POINT},
           }
        }, {
            STATE_POINT, {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP}
            }
        }, {
            STATE_POINT_WITHOUT_INT, {
                {CHAR_NUMBER, STATE_FRACTION},
            }
        }, {
            STATE_FRACTION, {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP}
            }
        }, {
            STATE_EXP, {
                {CHAR_NUMBER, STATE_EXP_NUMBER},
                {CHAR_SIGN, STATE_EXP_SIGN}
           }
        }, {
            STATE_EXP_SIGN, {
                {CHAR_NUMBER, STATE_EXP_NUMBER}
            }
        }, {
            STATE_EXP_NUMBER, {
                {CHAR_NUMBER, STATE_EXP_NUMBER}
            }
        }
    };
    int len = s.length();
    State st = STATE_INITIAL;
    for (int i = 0; i < len; i++) {
        CharType typ = toCharType(s[i]);
        if (transfer[st].find(typ) == transfer[st].end()) {
            return false;
        } else {
            st = transfer[st][typ];
        }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
}
