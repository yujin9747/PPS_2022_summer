/*
문자열 압축
https://programmers.co.kr/learn/courses/30/lessons/60057

미완
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 자르는 길이는 문자열의 총 길이의 절반까지만
// 그 이상으로 늘어나면 문자열 압축되지 않음

int solution(string s) {
    int answer = 0; // 압축한 문자열의 길이
    // 자르는 길이 len, 문자열의 총 길이 slen
    int len, slen = s.length(), min=slen, cnt;
    string sub, prev;
    for(len=1;len<=slen/2; len++){
        int i=0;
        while(i < slen){
            sub = s.substr(i, len);
            if(sub.length() < len) {
                answer += sub.length(); // 남은 문자열 길이 만큼 증가
                if(i != 0){
                    if(cnt != 1) answer++; // 이전까지의 검사 확인
                    answer += len;
                }
                break;
            }
            if(i == 0) {
                prev = sub;
                cnt = 1;
            }
            else if(sub.compare(prev) == 0) cnt ++;
            else{
                if(cnt != 1) answer++;
                answer += len;
                cnt = 1; // 새로운 문자 1번 연속 등장
                prev = sub;
            }
            if(i == slen) { // 마지막 문자였을 경우 자기 자신에 대해 cnt++ 한 후 종료
                if(cnt != 1) answer++;
                answer += len;
                break;
            }
            i += len;
        }
        
        if(answer < min) min = answer;
        answer = 0;
    }
    
    return min;
}

int main(){
    cout << solution("abcabcdede") << "\n";
    return 0;
}