/*
카드2
https://www.acmicpc.net/problem/2164
*/
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> card;
    for(int i=1; i<=n; i++) card.push(i);       // 가장 작은 숫자부터 queue의 front(즉, 카드의 제일 위)에 놓이도록 push
    while(card.size() != 1){
       card.pop();                              // 가장 위에 있는 요소 삭제
       card.push(card.front());                 // 가장 위에 있는 요소 카드의 맨 아래로 push
       card.pop();                              // 아래로 보낸 요소 삭제
    }
    cout << card.back();                        // 마지막에 남은 하나의 숫자 출력
    return 0;
}