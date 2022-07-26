/*
Determine if String Halves are alike
https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/
#include <iostream>
using namespace std;
class Solution {
public:
    char toLower(char ch){  // 문자를 소문자로 바꾼다
        if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
        return ch;
    }
    bool halvesAreAlike(string s) {
        // 절반으로 문자열을 나눈다
        string a = s.substr(0, s.length()/2);
        string b = s.substr(s.length()/2 , s.length()/2);
        int cntA=0, cntB=0; // 각 문자열에 속한 모음 갯수
        for(int i=0; i<s.length()/2; i++){
            // 문자를 소문자로 바꾼다
            a[i] = toLower(a[i]);
            b[i] = toLower(b[i]);
            // 모음이면 카운트를 증가한다
            if(a[i] == 'a' || a[i] == 'e' ||a[i] == 'i' || a[i] == 'o' || a[i] == 'u') cntA++;
            if(b[i] == 'a' || b[i] == 'e' ||b[i] == 'i' || b[i] == 'o' || b[i] == 'u') cntB++;
        }
        // 모음의 갯숙가 같으면 true를 반환한다
        if(cntA == cntB) return true;
        return false;
    }
};