/*
카이사르 암호
https://www.acmicpc.net/problem/5598
*/
#include <iostream>
#include <cstring>

using namespace std;
int main(){
    char str[1001];
    cin >> str;
    for(size_t i=0; i<strlen(str); i++) { 
        if(str[i] >= 'A' && str[i] <= 'C'){
            if(str[i] == 'A') cout << "X";
            else if(str[i] == 'B') cout << "Y";
            else cout << "Z";
        }
        else printf("%c", str[i] - 3); // ascii 코드가 3만큼 작은 문자 출력
    }
    return 0;
}