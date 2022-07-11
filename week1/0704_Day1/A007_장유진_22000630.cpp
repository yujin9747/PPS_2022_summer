/*
음계 판별하기
https://www.acmicpc.net/problem/2920
*/
#include <iostream>
using namespace std;
int main(){
    int a, ascending=1, descending=1;
    for(int i=0; i<8; i++) {
        cin >> a;
        if(a != i+1) ascending = 0; // ascending이 아닌 경우
        if(a != 8-i) descending = 0; // descending이 아닌 경우
    }
    if(ascending == 0 && descending == 0) cout << "mixed";
    else if(ascending == 1) cout << "ascending";
    else cout << "descending";
    return 0;
}