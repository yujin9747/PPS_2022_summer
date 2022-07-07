/*
문자열 다루기 기본
https://programmers.co.kr/learn/courses/30/lessons/12918
문자열이 숫자인지 확인(길이 4 또는 6)
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length() != 4 && s.length() != 6) answer = false; // false 조건 1
    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i]) == 0) answer = false; // false 조건 2
    }
    return answer;
}