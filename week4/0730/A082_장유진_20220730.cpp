/*
나이순 정렬
https://www.acmicpc.net/problem/10814
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct person{
    int age;
    string name;
    int i;    // 가입한 순서 from 0
    person(int a, string n, int idx):age(a), name(n), i(idx){}
};
struct cmp1{
    bool operator()(person a, person b){
        return a.age > b.age;
    }
};
struct cmp2{
    bool operator()(person a, person b){
        return a.i > b.i;
    }
};
int main(){
    int n, age;
    cin >> n;
    string name;
    priority_queue<person, vector<person>, cmp1 > q1;
    for(int i=0; i<n; i++){
        cin >> age >> name;
        person p(age, name, i);
        q1.push(p);
    }
    int curr_age = q1.top().age;
    priority_queue<person, vector<person>, cmp2 > q2;
    while(!q1.empty()){
        person p = q1.top();
        q1.pop();
        if(p.age == curr_age) q2.push(p);
        else{
            while(!q2.empty()){
                cout << q2.top().age << " " << q2.top().name << "\n";
                q2.pop();
            }
            curr_age = p.age;
            q2.push(p);
        }        
    }
    while(!q2.empty()){
        cout << q2.top().age << " " << q2.top().name << "\n";
        q2.pop();
    }
    return 0;
}