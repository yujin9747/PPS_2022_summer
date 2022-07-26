/*
JadenCase 문자열 만들기
https://programmers.co.kr/learn/courses/30/lessons/12951
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
char toLower(char ch){  // 소분자로 변환
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
    return ch;
}
char toUpper(char ch){  // 대문자로 변환
    if(ch >= 'a' && ch <= 'z') return ch - 'a' + 'A';
    return ch;
}
string solution(string s) {
    string answer = "";
    int i=0;    // s 내 문자의 위치
    while(i<s.length()){
        if(s[i] >= '1' && s[i] <= '9') {    // 숫자인 경우 
            answer += s[i];                 // 숫자 붙이기
            while(s[i] != ' ') {            // 공백 나오기 전까지 모든 문자 소문자로 붙이기
                i++;
                if(i == s.length()) return answer;  // 문장이 끝났을 경우 반환
                answer += toLower(s[i]);
            }
            i++;                            // 공백에서 끝났을 경우 : 새로운 단어의 첫 문자 위치로 이동
        }
        else{                               // 단어의 시작이 숫자가 아닌 문자인 경우
            answer += toUpper(s[i]);        // 첫 문자는 대문자로 붙이기 
            while(s[i] != ' ') {            // 공백 나오기 전까지 모든 문자 소문자로 붙이기
                i++;
                if(i == s.length()) return answer;  // 문장이 끝났을 경우 반환
                answer += toLower(s[i]);   
            }
            i++;                            // 공백에서 끝났을 경우 : 새로운 단어의 첫 문자 위치로 이동
        }
    }
    return answer;                          // 완성된 문자 반환
}

int main(){
    string answer = solution("3people unFollowed me");
    cout << answer;
    return 0;
}