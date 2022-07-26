/*
Backspace String Compare
https://leetcode.com/problems/backspace-string-compare/
*/
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> S, T;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '#' && S.size() != 0) S.pop();
            else if(s[i] == '#' && S.size() == 0){}
            else S.push(s[i]);
        }
        for(int i=0; i<t.length(); i++){
            if(t[i] == '#' && T.size() != 0) T.pop();
            else if(t[i] == '#' && T.size() == 0){}
            else T.push(t[i]);
        }
        if(S.size() != T.size()) return false;
        while(!S.empty()){
            if(T.top() != S.top()) return false;
            S.pop();
            T.pop();
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.backspaceCompare("xywrrmp", "xywrrm#p");
    return 0;
}