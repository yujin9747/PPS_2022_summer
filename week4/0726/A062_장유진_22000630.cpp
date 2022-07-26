/*
2016년
https://programmers.co.kr/learn/courses/30/lessons/12901
*/
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days=0;
    a--;
    while(a!=0) {
        days += month[a-1];
        a--;
    }
    days += b;
    int modulo = days%7;
    if(modulo == 0) answer = "THU";
    else if(modulo == 1) answer = "FRI";
    else if(modulo == 2) answer = "SAT";
    else if(modulo == 3) answer = "SUN";
    else if(modulo == 4) answer = "MON";
    else if(modulo == 5) answer = "TUE";
    else if(modulo == 6) answer = "WED";
    return answer;
}