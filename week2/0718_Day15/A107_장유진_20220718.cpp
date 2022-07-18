/*
쉽게 푸는 문제
https://www.acmicpc.net/problem/1292
*/
#include <iostream>
using namespace std;
/* 수열의 다음 수를 구하는 함수 */
void next(int& curr, int& repeat){
    // curr : 현재 숫자
    // repeat : 지금까지 반복된 숫자
    if(curr == repeat) {
        curr++;
        repeat = 1;
    }
    else repeat++;
}
int main(){
    int start=3, end=7;
    cin >> start >>  end;                                   // 구간을 입력받는다
    int curr = 1, repeat = 0, sum = 0;
    for(int i=0; i<start-1; i++) next(curr, repeat);        // 만약 [3, 7] 구간인 경우 12|2333 -> |위치 까지 이동
    for(int i=0; i<end-start+1; i++){                       // |다음 위치의 값을 구해 sum에 더한다 -> 7-3+1 만큼 반복(3~7사이 갑은 총 5개)
        next(curr, repeat);         
        sum += curr;
    }
    cout << sum;
    return 0;
}