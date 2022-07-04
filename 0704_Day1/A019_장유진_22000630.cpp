/*
숫자의 개수
https://www.acmicpc.net/problem/2577
*/
#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int m = a*b*c;
    int n[10] = {0};
    while(m != 0){
        n[m%10]++;
        m /= 10;
    }
    for(int i=0; i<10; i++) cout << n[i] << "\n";
    return 0;
}