/*
ACM 호텔
https://www.acmicpc.net/problem/10250
*/
/* 각각 호텔의 층 수, 각 층의 방 수, 몇 번째 손님인지를 나타낸다*/
#include <iostream>
using namespace std;
int main(){
    int T, W, H, N;
    cin >> T;    // 테스트 케이스 수
    for(int i=0; i<T; i++){
        cin >> W >> H >> N;    // 호텔의 층 수, 각 층의 방 수, 몇 번째 손님인지
        int w=0, h=1;
        for(int j=N; j>0; j--){
            if(w == W) {       // 해당 라인 모든 층의 방이 찼을 경우, 옆 방으로 이동
                w=1;
                h++;
            }
            else w++;          // 엘레베이터에서 같은 거리의 윗 층으로 이동
        }
        cout << w;
        if(h<10) cout << "0";
        cout << h << "\n";
    }
    return 0;
}