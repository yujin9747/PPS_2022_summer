/*
Valid Palindrome
*/
#include <iostream>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string alphabet;
        char lcase;
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])) alphabet += s[i];
            else{
                lcase = tolower(s[i]);
                if(lcase >= 'a' && lcase <= 'z') alphabet += lcase;
            }
        }
        int cmpIdx;
        for(int i=0; i<alphabet.length()/2; i++){
            cmpIdx = alphabet.length() - i - 1;
            if(alphabet[i] != alphabet[cmpIdx]) return false;
        }
        return true;
    }
};