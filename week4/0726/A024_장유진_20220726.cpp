/*
Lemonade Change
https://leetcode.com/problems/lemonade-change/
*/
#include <iostream>
#include <vector>

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int dolar[3] = {0, 0, 0};               // 가지고 있는 지폐 수를 0으로 초기화 한다
        for(int i=0; i<bills.size(); i++){  // 모든 주문에 대해 반복하며 true/false를 감별한다
            if(bills[i] == 5){              // 5달러를 받은 경우   
                dolar[0]++;                 // 거스름돈 없음. 5달러만 추가
            }
            else if(bills[i] == 10){        // 10달러를 받은 경우          
                dolar[1]++;                 // 10달러 추가
                if(dolar[0] == 0) return false; // 거스름돈 5달러가 없다면 false
                dolar[0]--;                 // 거스름돈 5달러가 있다면 차감
            }
            else if(bills[i] == 20){        // 20달러를 받은 경우
                dolar[2]++;                 // 20달러 추가
                if(dolar[1] == 0){          // 10달러짜리가 없다면 -> 5달러 3장 줘야 함
                    if(dolar[0] < 3) return false;  // 5달러가 3장 미만인 경우 false
                    dolar[0] -= 3;          // 아니면 5달러 3장 차감
                }
                else {                      // 10달러짜리가 있는 경우
                    if(dolar[0] == 0) return false; // 5달러가 없다면 false
                    dolar[0]--;             // 아니라면 10달러, 5달러 한 장씩 차감
                    dolar[1]--;
                }
            }
        }
        return true;                        // 모든 주문에 대해 거스름돈을 제대로 돌려 중었다면 true 반환
    }
};