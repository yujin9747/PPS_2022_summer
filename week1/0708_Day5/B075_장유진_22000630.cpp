/*
달나라 토끼를 위한 구매대금 지불 도우미
https://www.acmicpc.net/problem/17212
*/
#include <iostream>
#include <algorithm>
using namespace std;
// dp 이용해서 풀기
int main()
{
    int n;
    cin >> n;
    int dp[100001];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 1;
    for(int i=8; i<=n; i++){ // dp[n]을 구하기 위해 dp[8]부터 구하기 시작
        if(i % 7 == 0) dp[i] = n/7; // 가장 큰 동전인 7원으로 거스름돈 없이 지불 가능한 경우
        else dp[i] = min({dp[i-7], dp[i-5], dp[i-2], dp[i-1]})+1; // +1(7,5,2,1 중 지불한 하나의 동전), min():해당 동전을 하나 지불 한 후, 남은 돈에 대해 필요한 동전 갯수
    }
    cout << dp[n];
    return 0;
}