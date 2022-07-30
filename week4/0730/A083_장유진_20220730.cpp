/*
중복 빼고 정렬하기
https://www.acmicpc.net/problem/10867
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, input;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    int curr=-1;
    for(int i=0; i<v.size(); i++){
        if(v[i] != curr) {
            cout << v[i] << " ";
            curr = v[i];
        }
    }
    return 0;
}