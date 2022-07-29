/*
점수계산
https://www.acmicpc.net/problem/2822
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct element{
    int score;
    int problemN;
    element(int s, int n):score(s), problemN(n){}
};
struct cmp1{
    bool operator()(element a, element b){
        return a.score < b.score;   // 점수 기준 내림차순 정렬
    }
};
struct cmp2{
    bool operator()(element a, element b){
        return a.problemN > b.problemN; // 문제 번호 기준 오름차순 정렬
    }
};
int main(){
    int sum=0;
    int input;
    priority_queue<element, vector<element>, cmp1 > q;
    for(int i=0; i<8; i++){
        cin >> input;
        element e(input, i+1);  // 점수 기준 내림차순 정렬해서 큐에 저장
        q.push(e);
    }
    priority_queue<element, vector<element>, cmp2 > q2;
    for(int i=0; i<5; i++){
        sum += q.top().score;   // 상위 5개의 점수 더하기
        q2.push(q.top());   // 문제 번호 기준 오름차순 정렬해서 큐에 저장
        q.pop();
    }
    cout << sum << "\n";    // 합산 출력
    for(int i=0; i<5; i++){
        cout << q2.top().problemN << " ";   // 문제 번호 오름차순으로 출력
        q2.pop();
    }
    return 0;
}