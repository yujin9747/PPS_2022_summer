/*
지능형 기차
https://www.acmicpc.net/problem/2455
*/
#include <iostream>
using namespace std;
int main(){
    int in, out, n=0, max=0;
    for(int i=0; i<4; i++){
        cin >> in >> out;
        n -= in;
        n += out;
        if(n > max) max = n; 
    }
    cout << max;
    return 0;
}