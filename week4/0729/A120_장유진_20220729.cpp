/*
Find the Difference
https://leetcode.com/problems/find-the-difference/
*/
#include <iostream>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int alphabetS[26], alphabetT[26];   // s와 t에 들어있는 모든 문자 별로 들어있는 갯수를 구한다
        char ret;
        int i;
        for(i=0; i<26; i++) {   // 배열 초기화
            alphabetS[i] = 0;
            alphabetT[i] = 0;
        }
        for(i=0; i<s.length(); i++){    // 각 문자별로 총 몇 개가 들어있는지 구한다
            alphabetS[s[i]-'a']++;
            alphabetT[t[i]-'a']++;
        }
        alphabetT[t[i]-'a']++;          // 길이가 1 만큼 더 길기 때문에 한 번 더 구한다
        for(i=0; i<26; i++){
            if(alphabetS[i] != alphabetT[i]) ret = i + 'a'; // 각 알파벳이 들어있는 갯수가 다른 곳의 문자를 리턴값에 저장한다
        }
        return ret;
    }
};