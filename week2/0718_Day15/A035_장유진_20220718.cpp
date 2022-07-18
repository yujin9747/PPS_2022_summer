/*
화성 수학
https://www.acmicpc.net/problem/5355
*/
#include <iostream>
using namespace std;
int main(){
    /*
    아래의 두 줄의 코드를 지우니 시간 초과 오류가 해결 되었다.
    아래의 두 줄의 코드를 사용할 때에는 getchar, scanf, gets 등을 사용하면 안되는데 나의 코드에서는 사용했기 때문이다.
    */
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);

    int testcase, i;
    double number;                // number : 소숫점 첫째자리까지의 숫자 입력 & 둘째짜리 까지 출력
    char op;            
    cin >> testcase;
    while(testcase != 0){
        cin >> number;
        getchar();
        while(1){ 
            i = getchar();       
            if(i == '\n') break;
            else {
                op = i;
                if(op == '@') {
                    number *= 3;            // @ 입력 시, 곱하기 3
                }
                else if(op == '%') {
                    number += 5;            // % 입력 시, 더하기 5   
                }
                else if(op == '#') {
                    number -= 7;            // # 입력 시, 빼기 7
                }
            }
        }
        printf("%.2f\n", number);
        testcase--;
    }
    return 0;
}