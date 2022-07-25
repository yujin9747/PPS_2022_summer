/*
핸드폰 요금
https://www.acmicpc.net/problem/1267
*/
#include <iostream>
using namespace std;
int min(int sec){
    return (sec/60+1)*15;
}

int young(int sec){
    return (sec/30+1)*10;
}

int main(){
    int n, sec, M=0, Y=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> sec;
        M += min(sec);
        Y += young(sec);
    }
    if(Y == M) cout << "Y M " << M;
    else if(Y < M) cout << "Y " << Y;
    else cout << "M " << M;
    return 0;
}