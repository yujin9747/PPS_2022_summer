/*
스택

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

https://www.acmicpc.net/problem/10828
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n, pushInt;
    cin >> n;
    string command;
    stack<int> s;
    for(int i=0; i<n; i++){
        cin >> command;
        if(command == "push"){
            cin >> pushInt;
            s.push(pushInt);
        }else if(command == "pop"){
            if(s.size() != 0) {
                cout << s.top() << "\n";
                s.pop();
            }
            else cout << "-1\n";
        }else if(command == "size"){
            cout << s.size() << "\n";
        }else if(command == "empty"){
            if(s.size() == 0) cout << "1\n";
            else cout << "0\n";
        }else if(command == "top"){
            if(s.size() == 0) cout << "-1\n";
            else cout << s.top() << "\n";
        }
    }
    return 0;
}