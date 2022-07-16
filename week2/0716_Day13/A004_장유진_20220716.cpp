/*
나누어 떨어지는 숫자 배열
https://programmers.co.kr/learn/courses/30/lessons/12910
*/
#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;
// array 내 같은 숫자는 존재하지 않는다
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]%divisor == 0) answer.push_back(arr[i]); // return 할 vector에 삽입
    }
    if(answer.size() != 0) sort(answer.begin(), answer.end()); // return 하기 전 오름차순 sort
    else answer.push_back(-1);  // divisor로 나누어 떨어지는 숫자가 없을 경우 -1 삽입
    return answer;
}