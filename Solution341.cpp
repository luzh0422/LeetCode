//
// Created by luzh on 2021/3/23.
//

#include "Solution341.h"

NestedInteger::NestedInteger() {
    mIsInteger = false;
    mNums = {};
}

NestedInteger::NestedInteger(int num) {
    mIsInteger = true;
    mNum = num;
}

NestedInteger::NestedInteger(vector<NestedInteger> nums) {
    for (int i = 0; i < nums.size(); i++) {
        mNums.push_back(nums[i]);
    }
    mIsInteger = false;
}

int NestedInteger::getInteger() const {
    return mNum;
}

const vector<NestedInteger> & NestedInteger::getList() const {
    return mNums;
}

bool NestedInteger::isInteger() const {
    return mIsInteger;
}

NestedIterator::NestedIterator(vector<NestedInteger> &nestedList) {
    curr = 0;
    size = nestedList.size();
    this->mNestedList.assign(nestedList.begin(), nestedList.end());
    this->mNestedIterator = NULL;
}

int NestedIterator::next() {
    if (!this->hasNext()) {
        return -1;
    }
    NestedInteger nestedInteger = this->mNestedList[curr];
    int ans;
    if (nestedInteger.isInteger()) {
        /**
         * 如果nestedInteger是一个整数，则直接读取，并将Iterator + 1；
         */
        ans = nestedInteger.getInteger();
        curr++;
    } else {
        /**
         * 如果nestedInteger是一个列表，则要根据这个列表重新构建一个Iterator处理；
         */
        if (this->mNestedIterator == NULL) {
            vector<NestedInteger> temp = nestedInteger.getList();
            this->mNestedIterator = new NestedIterator(temp);
        }
        if (this->mNestedIterator->hasNext()) {
            /**
             * 如果构建的mNestedIterator有下一个，则继续返回；
             */
            ans = this->mNestedIterator->next();
            if (!this->mNestedIterator->hasNext()) {
                delete this->mNestedIterator;
                this->mNestedIterator = NULL;
                curr++;
            }
        } else {
            delete this->mNestedIterator;
            this->mNestedIterator = NULL;
            curr++;
        }
    }
    return ans;
}

bool NestedIterator::hasNext() {
   if (curr >= size) {
       return false;
   }
   if (!this->mNestedList[this->curr].isInteger()) {
       vector<NestedInteger> temp = this->mNestedList[this->curr].getList();
       NestedIterator temp2(temp);
       if (!temp2.hasNext()) {
           curr++;
           return this->hasNext();
       }
   }
    return true;
}

