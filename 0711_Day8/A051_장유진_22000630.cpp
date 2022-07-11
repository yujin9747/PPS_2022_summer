/*
다이얼
https://www.acmicpc.net/problem/5622
*/
#include <iostream>
/*
abc : 3초
def : 4초
ghi : 5초
jkl : 6초
mno : 7초
pqrs : 8초
tuv : 9초
wxyz : 10초
*/
using namespace std;
int main(){
    int result=0;
    string str;
    cin >> str;
    for(size_t i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'C') result += 3;
        else if(str[i] >= 'D' && str[i] <= 'F') result += 4;
        else if(str[i] >= 'G' && str[i] <= 'I') result += 5;
        else if(str[i] >= 'J' && str[i] <= 'L') result += 6;
        else if(str[i] >= 'M' && str[i] <= 'O') result += 7;
        else if(str[i] >= 'P' && str[i] <= 'S') result += 8;
        else if(str[i] >= 'T' && str[i] <= 'V') result += 9;
        else result += 10;  
    }
    cout << result;
    return 0;
}