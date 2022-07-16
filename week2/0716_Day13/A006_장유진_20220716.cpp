/*
문자열 내 p와 y의 갯수
https://programmers.co.kr/learn/courses/30/lessons/12916
*/
#include <string>
#include <iostream>
using namespace std;
/* 소문자로 변환 */
char tolower(char ch){
    if(ch >= 'a' && ch <= 'z') return ch;
    else return ch-'A'+'a';
}
bool solution(string s)
{
    bool answer = true;
    int p=0, y=0;
    char lowercase;
    
    for(int i=0; i<s.length(); i++){
        lowercase = tolower(s[i]);
        if(lowercase == 'p') p++;
        else if(lowercase == 'y') y++;
    }
    if(p != y) answer = false;          // p와 y의 최종 갯수가 다를 경우 false 

    return answer;
}