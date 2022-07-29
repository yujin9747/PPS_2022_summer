/*
최소공배수
https://www.acmicpc.net/problem/1934
*/
#include <iostream>
using namespace std;
int GCD(int a, int b){
    int remain = a%b;
    if(remain != 0) return GCD(b, remain);
    return b;
}
int main(){
    int n, a, b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        int gcd = GCD(a, b);    // 최대공약수를 구한다
        // 최소 공배수는 a와 b를 곱한 값을 최대공약수로 나눠서 구한다
        cout << (a*b)/gcd << "\n";
    }
    return 0;
}