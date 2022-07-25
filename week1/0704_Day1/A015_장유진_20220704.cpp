/*
검증수
https://www.acmicpc.net/problem/2475
*/
#include <iostream>
using namespace std;
int main(){
    int a, sum=0;
    for(int i=0; i<5; i++) {
        cin >> a;
        sum += a*a;
    }
    cout << sum%10;
    return 0;
}