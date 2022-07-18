/*
거스름돈
https://www.acmicpc.net/problem/5585
*/
#include <iostream>
using namespace std;
int main(){
    int payment, cnt=0;
    cin >> payment;                             // 지불 해야 하는 금액
    int change = 1000 - payment;                // 받아야 하는 거스름돈
    int coin[6] = {500, 100, 50, 10, 5, 1};     // 동전의 값
    while(change != 0){                         // 받아야 하는 거스름돈이 0원이 될 때까지 반복
        int i=0; 
        for(; i<6; i++) {
            if(coin[i] <= change) break;        // 거스름돈으로 사용할 수 있는 가장 큰 동전 하나 선택
        }
        change -= coin[i];                      // 받은 거스름돈 만큼 받아야 할 거스름돈 삭감 및 받은 동전 갯수 카운트
        cnt++;
    }
    cout << cnt;                                // 더이상 받아야 할 거스름돈이 없는 상태, 받은 동전 갯수 출력
    return 0;
}