/*
나머지
https://www.acmicpc.net/problem/3052
*/
#include <iostream>
#include <set>
using namespace std;
int main(){
    int a;
    set<int> s; // 42로 나눈 나머지를 중복을 허용하지 않고 모으는 자료 구조
    for(int i=0; i<10; i++){
        cin >> a;
        s.insert(a%42);
    }
    cout << s.size();
    return 0;
}