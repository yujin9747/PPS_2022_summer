/*
수 뒤집기
https://www.acmicpc.net/problem/3062
*/
#include <iostream>
#include <math.h>
using namespace std;
/* 뒤집은 수를 반한하는 합수 */
int reverseNumber(int n){
    int ret=0;
    while(n != 0){
        ret *= 10;
        ret += n%10;
        n /= 10;
    }
    return ret;
}

/* 두 수의 합이 대칭인지 반환하는 함수 */
bool symmetricSum(int a, int b){
    int sum = a+b;
    int reverseOfsum = reverseNumber(sum);
    if(sum == reverseOfsum) return true;
    return false;
}
int main(){
    int T, input, reverse;
    cin >> T;                           // test case 
    while(T != 0){
        cin >> input;                   // 테스트 할 숫자 입력
        reverse = reverseNumber(input);
        if(symmetricSum(input, reverse)) cout << "YES\n";
        else cout << "NO\n";
        T--;
    }
    return 0;
}