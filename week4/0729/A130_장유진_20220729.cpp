/*
제로
https://www.acmicpc.net/problem/10773
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;
    int n, input, sum=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> input;
        if(input == 0 && !s.empty()) s.pop();
        else s.push(input);
    }
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}