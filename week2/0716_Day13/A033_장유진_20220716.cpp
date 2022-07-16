/*
나는 요리사다
https://www.acmicpc.net/problem/2953
*/
#include <iostream>
using namespace std;
int main(){
    int sum, score, max=-1, max_i = -1;
    for(int i=0; i<5; i++){
        sum=0; 
        for(int j=0; j<4; j++){             // 각 참가자의 점수 총합 계산
            cin >> score;
            sum += score;
        } 
        if(sum > max) {                     // 현재 1위 update
            max = sum;
            max_i = i;
        }
    }       
    cout << max_i+1 << " " << max;          // 최종 1위 번호와 점수 출력
    return 0;
}