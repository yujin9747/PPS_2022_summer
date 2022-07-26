/*
하샤드수
https://programmers.co.kr/learn/courses/30/lessons/12947
*/
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum=0, temp = x;
    while(x != 0){
        sum += x%10;    // 일의 자리 수를 더한다
        x /= 10;        // 더한 일의 자리 수를 버린다
    }
    if(temp%sum == 0) answer = true;    // 모든 자리 수를 더한 값으로 나누어 떨어지는 경우 true
    else answer = false;
    return answer;
}