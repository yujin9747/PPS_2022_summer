/*
소트인사이드
https://www.acmicpc.net/problem/1427
*/
#include <iostream>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        return a < b;   // 오름차순 정렬
    }
};
int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> q;
    while(n != 0){  // 모든 숫자를 오름차순 정렬되는 우선 순위 큐에 넣는다
        q.push(n%10);
        n /= 10;
    }
    while(!q.empty()){  // 정렬된 숫자를 작은것 부터 차례대로 꺼내 출력한다
        cout << q.top();
        q.pop();
    }
    
    return 0;
}