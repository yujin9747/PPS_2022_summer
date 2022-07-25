/*
오르막길
https://www.acmicpc.net/problem/2846
*/

#include <iostream>
using namespace std;
int main(){
    int N, max=-1;
    cin >> N;
    int h[N], prev, start, ing=0;
    for(int i=0; i<N; i++) {
        cin >> h[i];
        if(i==0) { // 처음 들어오는 값인 경우
            prev = h[i];
        }
        else if(h[i] > prev){ // 오르막길
            if(ing == 0){ // prev에서 오르막길이 시작 된 경우
                start = prev; // 현재 오르막길이 시작된 위치 저장
                prev = h[i]; // 다음 높이와 비교 하기 위해 prev 값 변경
                ing = 1; 
            }
            else{
                prev = h[i];
                if(i==N-1 && prev - start > max) max = prev-start;
            }
        }
        else if(ing == 1){ // prev에서 오르막길이 끝난 경우
            if(prev - start > max) {
                max = prev - start;
            }
            prev = h[i];
            ing = 0;
        }
        else{ // 오르막길이 아닌 경우
            prev = h[i];
        }
    }
    if(max == -1) cout << "0";
    else cout << max;

    return 0;
}