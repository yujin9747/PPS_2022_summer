/*
Add Digits
https://leetcode.com/problems/add-digits/v
*/
class Solution {
public:
    int addDigits(int num) {
        int sum;
        while(1){ 
            sum = 0;
            while(1) {
                sum += num%10;                  // num의 1의자리 숫자 ++
                num /= 10;                      // num의 1의자리 숫자 버리기
                if(num == 0) break;             // num의 각 자리 숫자를 모두 더한 경우 break
            }
            if(sum/10 == 0) return sum;         // 새로 구한 값이 1자리 숫자면 return
            num = sum;                          // else : num을 sum으로 update 후, 다음 반복 진행       
        }
    }
};