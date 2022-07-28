#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
most sigificant digit이 가장 큰 것이 우선
같다면 least siginificant digit이 가장 큰 것이 우선
같다면 숫자가 더 작은 것이 우선 -> 숫자가 더 작으면 자릿수도 더 작음
*/
int calculate_Mdigit(int n){
    while(n >= 10){
        n /= 10;
    }
    return n;
}
typedef struct num{
    int value;  // 값
    int Mdigit; // most sigificant digit
    int Ldigit; // least sigificant digit
    num(int v) : value(v), Ldigit(v%10){
        Mdigit = calculate_Mdigit(v);
    }
}num;
struct cmpMdigit{
    bool operator()(num a, num b){
        return a.Mdigit < b.Mdigit;   // most sigificant digit이 큰 것 부터 정렬
    }
};
struct cmpLdigit{
    bool operator()(num a, num b){
        return a.Ldigit < b.Ldigit;   // least sigificant digit이 큰 것 부터 정렬
    }
};
struct cmpValue{
    bool operator()(num a, num b){
        a.value /= 10;
        b.value /= 10;
        return a.value%10 < b.value%10;  
    }
};
string solution(vector<int> numbers) {
    string answer = "";
    priority_queue<num, vector<num>, cmpMdigit> q;
    for(int i=0; i<numbers.size(); i++){
        num a(numbers[i]);
        q.push(a);
    }
    priority_queue<num, vector<num>, cmpLdigit> q2;
    priority_queue<num, vector<num>, cmpValue> q3;
    int currMdigit = q.top().Mdigit;
    while(!q.empty()){
        // answer = answer.append(to_string(q.top().value));
        if(q.top().Mdigit == currMdigit) q2.push(q.top());
        else {
            int currLdigit = q2.top().Ldigit;
            while(!q2.empty()){
                if(q2.top().Ldigit == currLdigit) q3.push(q2.top());
                else{
                    while(!q3.empty()){
                        answer = answer.append(to_string(q3.top().value));
                        q3.pop();
                    } 
                    q3.push(q2.top());
                    currLdigit = q2.top().Ldigit;
                }
                q2.pop();
            }
            while(!q3.empty()){
                answer = answer.append(to_string(q3.top().value));
                q3.pop();
            }
            q2.push(q.top());
            currMdigit = q.top().Mdigit;
        }
        q.pop();
    }
    while(!q2.empty()){
        answer = answer.append(to_string(q2.top().value));
        q2.pop();
    }
    return answer;
}

int main(){
    vector<int> numbers;
    numbers.push_back(677);
    numbers.push_back(67);
    numbers.push_back(676);
    // numbers.push_back(0);
    // numbers.push_back(0);
    string ret = solution(numbers);
    cout << ret;
    return 0;
}