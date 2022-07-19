/*
Add Binary
https://leetcode.com/problems/add-binary/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // return pair<summation, carry>
    // half Adder function
    // 두 수 중 하나가 1인 경우 sum = 1, carry = 0
    // 두 수 중 두 개가 1인 경우 sum = 0, carry = 1
    // 둘 다 0인 경우 sum = 0, carry = 0
    pair<char, char> adder(char a, char b){
        if(a == b && a == '1') return make_pair('0', '1');
        else if(a != b && ( a == '1' || b == '1')) return make_pair('1', '0');
        return make_pair('0', '0');
    }
    string addBinary(string a, string b) {
        /*
        a3, a2, a1
      + b3, b2, b1
     c4 c3, c2, c1
        ----------
     c4, s3, s2, s1
     
        c1의 초기값 : 0
        셋 중 1이 2개 이상인 경우 : carry는 1
        셋 중 1이 1개인 경우 : carry는 0
        셋 중 1이 1개 또는 3개인 경우 : sum은 1
        셋 중 1이 2개인 경우 : sum은 0
        
        두 수를 먼저 더하고, 그 결과와 남은 수를 더한 결과 : sum
        두 수를 먼저 더한 후 나온 carry와, 남은 수를 더한 후 나온 carry 중 하나라도 1이면 : carry = 1
        half adder 를 두 번 사용해 full adder를 구현한다

        a.length() = 5, b.length() = 3 인 경우
        a[4] 와 b[2]부터 더해야 한다 -> index = length-1-i
        */
        int i;
        char carry = '0';
        pair<char, char> firstAdd, secondAdd;
        string ret;
        int lengthA = a.length(), lengthB = b.length();
        
        // summation 할 때 most lowest bit 부터 더하기 위해, string's length - 1 - i 번째 요소에 대해 add 한다
        // -------  Summation -----------
        for(i=0; i<lengthA; i++){
            if(i == lengthB){                                           // b는 끝나고, a가 남은 경우
                while(i<lengthA) {                                      // carry와 a의 남은 숫자 모두 add
                    firstAdd = adder(a[lengthA -1 - i], carry);

                    string argument;
                    argument += firstAdd.first;                         // cast from char to string          
                    ret = ret.insert(0, argument);                      // 문자열의 앞에 sumi 붙이기        

                    if(firstAdd.second == '0') carry = '0';             // update carry out
                    else carry = '1';
                    
                    i++;                                                // a's next bit 
                }
                // post conditon : i == a.length()
                if(firstAdd.second == '1') ret = ret.insert(0, "1");    // if last carry out is 1(위의 주석 중 c4 : 0이면 붙이지 않는다)
                return ret;                                             // 종료 1: a가 b보다 긴 경우
            }

            // a와 b모두 bit가 남아있는 경우
            firstAdd = adder(a[lengthA - 1 - i], b[lengthB - 1 - i]);   // half adder 1 : ai+bi
            secondAdd = adder(firstAdd.first, carry);                   // half adder 2 : sumi + carry(obtained from lower bit addition)

            string argument;
            argument += secondAdd.first;                                // cast from char to string
            ret = ret.insert(0, argument);                              // 문자열 앞에 sumi 붙이기
            
            if(firstAdd.second == '1' || secondAdd.second == '1') carry = '1'; // 두 half addition 중, 하나라도 carry가 1이 나온 경우(+둘 다 1이 나온 경우는 존재 하지 않는다)
            else carry = '0';  
        }
        // post condition : i == lengthA -> a 종료
        // b의 남은 bit가 없을 때까지 한 번의 half adder 반복
        while(i<lengthB) { 
            firstAdd = adder(b[lengthB - 1 - i], carry);                // one half adder : b의 남은 bit와 carry

            string argument;
            argument += firstAdd.first;                                 // cast from char to string
            ret = ret.insert(0, argument);                              // 문자열의 앞에 sumi 붙이기
                    
            if(firstAdd.second == '0') carry = '0';                     // update carry
            else carry = '1';
                    
            i++;                                                        // b's next bit 
        }
        // post conditon : i == b.lengthB
        if(carry == '1') ret = ret.insert(0, "1");                  // if last carry out is 1(위의 주석 중 c4)

        return ret;                                                 // 종료 2 : b가 a보다 길거나 같은 경우
    }
};

int main(){
    Solution s;
    string str = s.addBinary("11", "1");
    cout << str;

    return 0;
}