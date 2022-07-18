/*
분수찾기
https://www.acmicpc.net/problem/1193
*/
#include <iostream>
using namespace std;
int main(){
    int n, i, j, depth=0, cnt=0;                // depth : 대각선이 꺾인 횟수, cnt : 몇 번째 분수인지, i/j 분수      
    cin >> n;                                   // 몇 번째 분수를 찾기 원하는지 입력받는다
    while(1){
        if(depth == 0) {                        // 첫 대각선인 경우 1/1로 초기화 및 depth 증가
            i=1;
            j=1;
            depth++;
        }
        else if(depth%2 == 1){                  // 홀수 번 꺾인 대각선인 경우 (좌하향)
            if(j != depth) i--;                 // 왼쪽 벽에 도달하기 전이라면(또 다시 꺾이는 곳) i 감소하며 하향
            else depth++;                       // 왼쪽 벽에 도달했다면 depth 증가
            j++;                                // 꺾임과 상관 없이 j 증가하며 좌향
        }
        else if(depth%2 == 0){                  // 짝수 번 꺾인 대각선인 경우 (우상향)
            if(i != depth) j--;                 // 위쪽 벽에 도달하기 전이라면(또 다시 꺾이는 곳) j 감소하며 상향
            else depth++;                       // 위쪽 벽에 도달했다면 depth 증가
            i++;                                // 꺾임과 상관 없이 i 증가하며 우향
        }
        cnt++;
        if(cnt == n) {                          // 찾고자하는 분수에 도달했을 경우 출력
            cout << i << "/" << j;
            break;
        }
    }
    return 0;
}