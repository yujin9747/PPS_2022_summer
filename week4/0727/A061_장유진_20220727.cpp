/*
Excel Sheet Column Title
https://leetcode.com/problems/excel-sheet-column-title/
*/
#include <iostream>
using namespace std;

class Solution {
public:
    char toAlphabet(int n){ //
        if(n == 0) return 'Z';
        return n - 1 + 'A';
    }
    string convertToTitle(int columnNumber) {
        string ret = "";
        /*
        26으로 나눈 나머지를 구한다.
        나머지에 따라 알파벳 결정
        columntitle의 가장 오른쪽 문자부터 결정된다
        string의 가장 앞에 계속해서 하나의 문자를 붙인다.
        하나의 알파벳을 결정 한 이후, columnNumber를 1만큼 줄인 후, 26으로 나눈 몫을 구한다.
        이 값이 0이면 종료한다. 
        -1을 하는 이유는?
        만약 columnNumber가 52였을 경우 나머지는 0이고, Z가 title에 추가된다. 
        column이 0부터 A로 시작하지 않고 1부터 A로 시작하기 때문에 26의 배수가 들어왔을 경우 나머지가 0인 Z를 추가한 후 26으로 나눈 몫보다 하나 작은 값만큼 더 반복해야 한다
        */
        while(columnNumber > 0){
            char alphabet = toAlphabet(columnNumber%26);
            ret.insert(0, &alphabet, 1);
            columnNumber--;
            columnNumber /= 26;
        }
        return ret;
    }
};