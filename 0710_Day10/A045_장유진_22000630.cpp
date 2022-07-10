/*
단어 공부
https://www.acmicpc.net/problem/1157
*/
#include <iostream>
using namespace std;
int toNumber(char ch){ // alphabet 배열 인덱스 반환
    if(ch >= 'a' && ch <= 'z') return ch - 'a';
    else return ch - 'A';
}
char toChar(int max_i){ // alphabet 인덱스에 해당하는 문자 반환
    return max_i + 'A';
}
int main(){
    string str;
    cin >> str;
    int alphabet[26] = {0};
    int index, max=0, max_i, flag=0;
    for(size_t i=0; i<str.size(); i++){
        index = toNumber(str[i]);
        alphabet[index]++; // 문자 출현 횟수 증가
    }
    for(int i=0; i<26; i++){
        if(alphabet[i] > max) {
            max = alphabet[i]; // 최대 출현 빈도 update
            max_i = i;
            flag = 0; // 출현 빈도 중복 해제
        }
        else if(alphabet[i] == max){
            flag = 1; // 출현 빈도 중복 체크
        }
    }
    if(flag == 1) cout << "?";
    else cout << toChar(max_i);
    return 0;
}