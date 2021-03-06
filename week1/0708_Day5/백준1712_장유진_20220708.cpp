/*
손익분기점
https://www.acmicpc.net/problem/1712
*/
#include <iostream>
using namespace std;
int main(){
    unsigned int a; // 고정 비용 -> 10억원 이하의 숫자 
    int b, c; 
    cin >> a >> b >> c;
    if(c-b <= 0) cout << "-1"; // 1대 생산 비용이 판매 수익보다 크거나 같은 경우 손익분기점을 넘을 수 없다
    else{
        a /= c-b; // 1대를 생산할 때마다 얻을 수 있는 수입(c-b)로 고정 비용을 나눠 몇 대를 팔아야 고정 비용을 넘을 수 있는지 계산
        cout << a+1; // 위에서 구한 값에서 한 대 더 팔면 손익분기점을 넘는다
    }

    /*
    ex. 2100000000 고정 비용, 9 가변비용, 10 판매수입 인 경우 
    한 대를 팔아 얻을 수 있는 실제 수입 1로 2100000000를 나누면 2100000000대 + 1 개를 팔아야 총 수입이 총 비용을 넘는다
    */
    return 0;
}