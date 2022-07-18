/*
3000번 버스
https://www.acmicpc.net/problem/9546
*/
#include <iostream>
#include <math.h>
using namespace std;
/*
처음 승객 수 - 모두 내리기까지 필요한 정류장 갯수
1 - 1 : 정류장 수 1일 때 1출력
2 - x
3 - 2 : 정류장 수 2일 때 2 출력
4 - x
5 - x
6 - x
7 - 3 : 정류장 수 3일 때 7 출력
8 - x

x : 절반과 반 명을 내리게 한 후, 남은 승객이 실수일 경우

마지막 정류장에서 승객이 없는 경우 가능한 처음 승객 수는 
1, 3, 7, 15, 31 ... : 2의 i 제곱만큼 더한 수
*/
int main(){
    int T, busStation , i, passenger;
    cin >> T;
    while(T != 0){
        cin >> busStation;
        passenger = 0;
        for(i=0; i<busStation; i++) passenger += pow(2, i);
        cout << passenger << "\n";
        T--;
    }
    return 0;
}