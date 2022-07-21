/*
Plus One
https://leetcode.com/problems/plus-one/
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
        1을 더하면 least significant digit을 ++ 하고
        만약 0이 되었다면 그 앞의 digit을 ++한다. 
        ++하고, 0인지 확인하고, 앞의 digit으로 이동하는 과정을 반복한다. 
        0이 아닌 경우 반복을 종료 하거나, most significant digit이었을 경우 종료한다
        만약 두 번째 조건으로 종료 했는데 most significant digit도 0이라면 vector의 맨 앞에 1을 추가한다
        array 보다 vector를 사용하면 좋은 점은 수의 자리수가 늘어날 때 맨 앞에 숫자를 추가해 주기 용이하기 때문이다
        */
        int i=digits.size()-1;                                  // least significatn digit의 위치
        while(i >= 0){                                          // most siginificant digit까지 반복
            if(digits[i] == 9){                                 // 현재 digit이 9인 경우, 0으로 변경 후 다음 digit의 위치로 이동
                digits[i] = 0 ;
                i--;
            }
            else{                                               // 현재 digit이 9가 아닌 경우, 1 증가 후 종료
                digits[i]++;
                break;
            }
        }
        if(digits[0] == 0) digits.insert(digits.begin(), 1);    // most siginificant digit이 0인 채로 종료 된 경우, new most siginificant digit인 1을 맨 앞에 삽입한다
        return digits;
    }
};