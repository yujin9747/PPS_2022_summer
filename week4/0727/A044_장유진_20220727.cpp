/*
Student Attendance Record 1
https://leetcode.com/problems/student-attendance-record-i/
*/
#include <iostream>
using namespace std;

class Solution {
public:
    /*
    late는 총 갯수는 상관 없다. 
    연속되는 지각이 3일 이상일 경우 false
    absent는 한 번까지는 괜찮다. 2번 이상일 경우 false
    */
    bool checkRecord(string s) {
        int totalA=0, consecutiveL=0;   // consecutiveL은 A혹은 P가 나올 때마다 0으로 초기화 된다
        for(int i=0; i<s.length(); i++){            
            if(s[i] == 'A') {
                totalA++;               // 총 결석 횟수를 증가한다
                consecutiveL = 0; 
            }
            else if(s[i] == 'L') consecutiveL++;    // 연속으로 지각한 횟수를 증가한다
            else if(s[i] == 'P') consecutiveL = 0;
            
            if(consecutiveL == 3 || totalA > 1) return false;
        }
        return true;
    }
};