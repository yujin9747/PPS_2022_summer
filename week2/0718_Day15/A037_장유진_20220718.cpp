/*
Self Dividing Numbers
https://leetcode.com/problems/self-dividing-numbers/
*/
#include <iostream>
#include <vector>
class Solution {
public:
    /* n이 self dividing 숫자인지 반환 (ex. 128 % 8 == 0, 128 % 2 == 0, 128 % 1 == 0) */
    bool selfDividing(int n){
        int temp = n;
        while(temp != 0){
            if(temp%10 == 0) return false;              // 숫자의 각 자리에 0이 있으면 self dividing 하지 않다
            else if(n % (temp%10) != 0) return false;   // 나누어 떨어지지 않는 경우 
            temp /= 10;                                 // more siginificant digit을 %로 뽑아내기 위해 나누기
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i=left; i<=right; i++){
            if(selfDividing(i)) ret.push_back(i);
        }
        return ret;
    }
};