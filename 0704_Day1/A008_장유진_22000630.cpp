/*
평균은 넘겠지
https://www.acmicpc.net/problem/4344
*/
#include <iostream>
#include <cmath> // round()
using namespace std;
int main(){
    int testCase, students, sum, avg, higher;
    cin >> testCase;
    for(int i=0; i<testCase; i++){
        cin >> students;
        int scores[students];
        sum = 0;
        // 총 합계 구하기
        for(int j=0; j<students; j++){
            cin >> scores[j];
            sum += scores[j];
        }
        // 평균을 넘는 학생 수 구하기
        avg = sum/students;
        higher = 0;
        for(int j=0; j<students; j++){
            if(scores[j] > avg) higher++;
        }
        // 소숫점 4째 자리에서 반올림해서 출력
        printf("%.3f", round(((double)higher/students*100)*1000)/1000); 
        cout << "%\n";
        
    }
    return 0;
}