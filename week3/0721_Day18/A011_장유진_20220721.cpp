/*
실패율
https://programmers.co.kr/learn/courses/30/lessons/60057
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
/*
1. 실패율 구하기
stages의 처음 크기는 전체 유저 수이다. 
입출력 예#1의 처음 stages 크기는 8이다. 
따라서 총 8명의 user가 존재하고, 각 user가 현재 어떤 stage에 머물러 있는지를 나타낸다
N에 따라 i = 1~N+1까지 늘려 가며 각 stage에 머물러 있는 유저의 수를 구한다.
1 stage에 머물러 있는 사람의 수는 1명이다. 
1 stage를 도전한 사람의 수는 8명이다. 
2 stage에 머물러 있는 사람의 수는 3명이다. 
2 stage에 도전한 사람 수는 7명이다. 

머물러 있는 사람의 수 : stages 배열 내 i의 갯수
도전한 사람의 수 : 8에서 이전 단계에 머물러 있던 사람 수를 계속해서 차감해 나간다

2. 실패율이 큰 stage 부터 내림차순으로 정렬하기
*/

struct stageInfo{                                               // stage 마다 stage 번호, 실패 율을 저장한 구조체를 가진다
    double rateOfFaile;
    int stageN;
    stageInfo(double f, int n):rateOfFaile(f), stageN(n){}
};

struct cmp1{                                                    // 정렬하는 첫 번째 기준 -> priority queue의 연산자로 사용한다
    // 실패율이 큰 것이 top을 이룬다
    bool operator()(stageInfo a, stageInfo b){
        return a.rateOfFaile < b.rateOfFaile;
    }
};
struct cmp2{                                                    // 정렬하는 두 번째 기준 -> priority queue의 연산자로 사용한다
    // stageN이 작은 것이 top을 이룬다
    bool operator()(stageInfo a, stageInfo b){
        return a.stageN > b.stageN;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<stageInfo, vector<stageInfo>, cmp1> q;       // 첫 번째 기준에 따라 stageInfo를 정렬해 저장한다
    priority_queue<stageInfo, vector<stageInfo>, cmp2> secondQ; // 두 번째 기준에 따라 stageInfo를 정렬해 저장한다 -> 실패율이 같은 stage끼리만 저장한다
    int stayed, tried = stages.size();                          // 머물러 있는 사람의 수, 도전한 사람의 수           
    double rateOfFaile;                                         // 실패율         
    for(int i=0; i<N; i++){                                     // 각 stage마다 실패율 계산
        stayed = 0;
        for(int k=0; k<stages.size(); k++)
            if(stages[k] == i+1) stayed++;                      // 각 stage에 머물러 있는 사람의 수 계산
        if(stayed != 0) rateOfFaile = stayed/(tried*1.0);       // 실패율 계산
        else rateOfFaile = 0;
        stageInfo s(rateOfFaile, i+1);
        q.push(s);                                              // stageInfo 구조체 만들어 queue에 삽입 -> 자동으로 실폐율이 큰 것 순으로 정렬된다
        tried -= stayed;                                        // 다음 스테이지를 도전한 사람 수 계산
    }
    while(1){
        if(q.empty()) break;                                    // 종료 조건 1 : q가 비었을 경우 -> 첫 번째 inner while 문 내에서 q가 모두 비는 경우
        stageInfo s = q.top();
        q.pop();
        if(q.empty()) {                                         // 종료 조건 2 : 마지막 stageInfo를 꺼낸 경우
            answer.push_back(s.stageN);
            break;
        }
        if(s.rateOfFaile != q.top().rateOfFaile) answer.push_back(s.stageN);    // 현재 stageInfo의 실패율과 다음 stageInfo의 실패율이 같지 않은 경우 answer에 현재 stageN 삽입
        else{
            while(s.rateOfFaile == q.top().rateOfFaile && !q.empty()){          // 실패율이 같은 stageInfo를 모두 q에서 꺼내 stageN에 따라 정렬해주는 secondQ에 삽입한다
                secondQ.push(s);
                s = q.top();
                q.pop();
            }
            secondQ.push(s);                                                    // 실패율이 같은 stageInfo 중 마지막 요소를 secondQ에 삽입한다
            while(!secondQ.empty()) {                                           // secondQ가 빌 때까지 stageN 순으로 정렬된 요소를 꺼내 answer에 stageN 정보를 삽입한다
                answer.push_back(secondQ.top().stageN);
                secondQ.pop();
            }
        }
    }
    return answer;
}

int main(){
    vector<int> stages;
    // answer : 3, 4, 2, 1, 5
    // stages.push_back(2);
    // stages.push_back(1);
    // stages.push_back(2);
    // stages.push_back(6);
    // stages.push_back(2);
    // stages.push_back(4);
    // stages.push_back(3);
    // stages.push_back(3);

    // answer : 4, 1, 2, 3
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    solution(4, stages);
    return 0;
}