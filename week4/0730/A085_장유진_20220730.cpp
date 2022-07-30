/*
시리얼 번호
https://www.acmicpc.net/problem/1431
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct serial{
    int sum;    // 숫자만 더한 값
    string serialName;
    int length;    // 문자열의 길이
    //int ascii[];
    serial(){}
    serial(string s, int l):sum(0), serialName(s), length(l){}
};
struct cmpLength{
    bool operator()(serial a, serial b){
        return a.length > b.length;
    }
};
struct cmpSum{
    bool operator()(serial a, serial b){
        return a.sum > b.sum;
    }
};
bool cmp(string a, string b){
    return a < b;
}
int main(){
    int n;
    cin >> n;
    string s;
    priority_queue<serial, vector<serial>, cmpLength > q1;
    for(int i=0; i<n; i++){
        cin >> s;
        serial a(s, s.length());
        int sum = 0;
        for(long unsigned int j=0; j<s.length(); j++){
            if(isdigit(s[j])) {
                int integer = s[j] - '0';
                sum += integer;
            }
        }
        a.sum = sum;
        q1.push(a);
    }
    priority_queue<serial, vector<serial>, cmpSum > q2;
    int curr_length = q1.top().length;
    while(!q1.empty()){
        serial a = q1.top();
        q1.pop();
        if(a.length == curr_length) {
            q2.push(a);
        }
        else{
            //priority_queue<serial, vector<serial>, cmpAlphabet > q3;
            vector<string> v;
            int curr_sum = q2.top().sum;
            while(!q2.empty()){
                serial b = q2.top();
                q2.pop();
                if(b.sum == curr_sum) {
                    v.push_back(b.serialName);
                }
                else{
                    sort(v.begin(), v.end(), cmp);
                    while(!v.empty()){
                        cout << v.front() << "\n";
                        v.erase(v.begin());
                    }
                    curr_sum = b.sum;
                    v.push_back(b.serialName);
                }
            }
            sort(v.begin(), v.end(), cmp);
            while(!v.empty()){
                cout << v.front() << "\n";
                v.erase(v.begin());
            }
            q2.push(a);
            curr_length = a.length;
        }
    }
    int curr_sum = q2.top().sum;
    vector<string> v;
    serial b;
    while(!q2.empty()){
        b = q2.top();
        q2.pop();
        if(b.sum == curr_sum) {
            v.push_back(b.serialName);
        }
        else{
            sort(v.begin(), v.end(), cmp);
            while(!v.empty()){
                cout << v.front() << "\n";
                v.erase(v.begin());
            }
            curr_sum = b.sum;
            v.push_back(b.serialName);
        }
    }
    sort(v.begin(), v.end(), cmp);
    while(!v.empty()){
        cout << v.front() << "\n";
        v.erase(v.begin());
    }
    curr_sum = b.sum;
    v.push_back(b.serialName);

    return 0;
}