/*
보물
https://www.acmicpc.net/problem/1026
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pair{
    int number;
    int position;
    Pair(int n, int p):number(n), position(p){};
};

struct cmpL {
    // number가 큰 것이 queue의 top에 위치하게 하는 연산자
    bool operator()(Pair a, Pair b) {
        return a.number < b.number;
    }
};
struct cmpS {
    // number가 작은 것이 queue의 top에 위치하게 하는 연산자
    bool operator()(Pair a, Pair b) {
        return a.number > b.number;
    }
};
int main(){
    int n, temp;
    cin >> n;
    vector<int> a, b;
    priority_queue<Pair, vector<Pair>, cmpS> a_sorted;
    for(int i=0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
        a_sorted.push(Pair(temp, i)); // 오름 차순 정렬
    }
    priority_queue<Pair, vector<Pair>, cmpL> b_sorted;  
    for(int i=0; i<n; i++){
        cin >> temp;
        b.push_back(temp);
        b_sorted.push(Pair(temp, i)); // 내림 차순 정렬
    }
    int sum = 0;
    while(!b_sorted.empty()){
        sum += a_sorted.top().number * b_sorted.top().number; // a의 가장 작은 값과 b의 가장 큰 값을 곱해서 더하기
        a_sorted.pop();
        b_sorted.pop();
    }
    cout << sum;
    return 0;
}