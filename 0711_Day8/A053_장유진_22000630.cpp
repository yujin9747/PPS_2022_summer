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
#include <vector>
using namespace std;
int main(){
    int N, integerX;
    cin >> N;
    string command;
    vector<int> v;
    for(int i=0; i<N; i++){
        cin >> command;
        if(command.compare("push") == 0) {
            cin >> integerX;
            v.push_back(integerX);
        }
        else{
            if(command.compare("pop") == 0){
                if(v.empty()) cout << "-1\n";
                else {
                    cout << v.back() << "\n";
                    v.pop_back();
                }
            } else if(command.compare("top") == 0){
                if(v.empty()) cout << "-1\n";
                else cout << v.back() << "\n";
            } else if(command.compare("empty") == 0){
                if(v.empty()) cout << "1\n";
                else cout << "0\n";
            } else if(command.compare("size") == 0) cout << v.size() << "\n";
        }
    }
    return 0;
}