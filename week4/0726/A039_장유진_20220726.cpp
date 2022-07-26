/*
Valid Perfect Square
https://leetcode.com/problems/valid-perfect-square/
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        /*
        숙수념에 나오는 제곱근 구하는 방법 방법은 아주 간단해요. 제곱근을 구하려고 하는 수를 2로 나눈 다음에 그 수에서 1부터 2, 3, 4의 오름차순으로 계속 빼주는 거예요. 그러다 더는 뺄 수 없을 때(음수가 나올 때) 앞에서 뺀 결과로 나온 수와 빼야 하는 수를 비교하는 거지요.
        */
        long long temp = num;
        temp /= 2;
        int i=1;
        while(1){
            temp -= i;
            if(temp < 0) break;
            i++;
        }
        if(((temp+i) - temp) * ((temp+i) - temp) == num) return true;
        return false;
    }
};