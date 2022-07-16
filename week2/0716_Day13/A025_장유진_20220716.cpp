/*
Power of Four
https://leetcode.com/problems/lemonade-change/
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n != 1){
            if(n%4 != 0) return false;      // 4의 배수가 아니면 false
            n /= 4;
            if(n == 0) return false;        // 4의 배수이면서 power of four는 아닌 경우 false  
        }
        return true;                        // n이 1이 될 때까지 4로 나누어 진 경우 true
    }
};