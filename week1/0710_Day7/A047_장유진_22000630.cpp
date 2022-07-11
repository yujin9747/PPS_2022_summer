/*
열 개씩 출력하기
https://www.acmicpc.net/problem/11721
*/
#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    for(size_t i=0; i<str.size(); i++){
        cout << str[i];
        if(i%10 == 9) cout << "\n";
    }
    return 0;
}