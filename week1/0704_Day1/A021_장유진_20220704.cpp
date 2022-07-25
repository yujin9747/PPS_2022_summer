/*
플러그
https://www.acmicpc.net/problem/2010
*/
#include <iostream>
using namespace std;
int main(){
    int Psocket, n, sum=0;
    cin >> Psocket;
    for(int i=0; i<Psocket; i++) {
        cin >> n;
        sum += n;
    }
    sum -= Psocket-1;
    cout << sum;
    return 0;
}