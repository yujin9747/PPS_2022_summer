/*
Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/
*/
#include <vector>
using namespace std;

class Solution {
public:
    //  1 <= numRows <= 30
    vector<vector<int>> generate(int numRows) {
        vector<int> eachRow;
        vector<vector<int>> ret;
        for(int i=0; i<numRows; i++){
            if(i == 0) {                        // 첫 번째 줄인 경우 1만 넣은 후 ret에 push
                eachRow = {1};
                ret.push_back(eachRow);
            }
            else {
                eachRow = {1, 1};               // 맨 앞과 맨 뒤의 숫자를 1로 설정
                // 가운데 숫자 채우기
                // v.insert(삽입할 위치의 주소 값, 변수 값) 함수 이용
                for(int j=0; j<i-1; j++){       // 몇 번째 row인 지에 따라 채워야 할 가운데 숫자가 달라진다 ( 3번쨰 줄인 경우 1개의 가운데 숫자를 채운다)
                    int value;                  // 윗 줄의 두 수를 더한 값
                    value = ret[i-1][j] + ret[i-1][j+1];    // 바로 윗 줄의 왼쪽, 오른쪽 숫자를 더한다. 왼쪽, 오른쪽 숫자는 j에 따라 결정된다
                    eachRow.insert(eachRow.begin()+j+1, value); 
                }
                ret.push_back(eachRow);
            } 
            eachRow.clear();                    // push 후 eachRow 비우기
        }
        return ret;

        /*
        실행 모습 예시
        3번째 줄은 {1, 2, 1}
        4번째 줄인 경우 else 문 내 실행 모습
        eachRow = {1, 1}
        for문 j=0, 1 두 번 반복
        j=0 일 때 value는 바로 윗 줄의 맨 처음과 바로 다음 숫자를 더한 값을 eachRow의 첫 숫자 바로 뒤에 삽입한다
        eachRow = {1, 3, 1};
        j=1 일 때 value는 바로 윗 줄의 두 번째 숫자와 세 번째 숫자를 더한 값을 방급 삽입한 중간 숫자의 바로 뒤에 삽입한다
        eachRow = {1, 3, 3, 1};
        */
    }
};