/*
농구 경기
https://www.acmicpc.net/problem/1159
*/
#include <iostream>
using namespace std;

int toNumber(char ch){
    if(ch >= 'a' && ch <= 'z') return ch - 'a';
    return ch - 'A';
}
int main(){
    int N, lastName[26] = {0}, index, max = 0; // a~z 로 시작하는 성의 개수를 저장
    cin >> N;
    string name;
    for(int i=0; i<N; i++){
        cin >> name;
        index = toNumber(name[0]);
        lastName[index]++;
        if(lastName[index] > max) max = lastName[index]; // 같은 글자로 시작하는 성의 최대 갯수
    }
    if(max < 5) cout << "PREDAJA"; // 5명 이하일 경우 : 기권
    else {
        for(int i=0; i<26; i++) // 알파벳 순서대로 같은 성이 5명 이상인 경우 공백없이 출력
            if(lastName[i] >= 5) printf("%c", i+97); // ascii code 'a' 십진수 : 97
    }
    
    return 0;
}