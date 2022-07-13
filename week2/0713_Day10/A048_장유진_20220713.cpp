/*
그룹 단어 체커
https://www.acmicpc.net/problem/1316

ab, aabbc, a : 그룹 단어
aba, study : 그룹 단어 아님
*/
#include <iostream>
using namespace std;
int toNumber(char ch){ // 전제 조건 : 소문자만 입력된다.
    return ch - 'a'; // 단어의 alphabet 배열 내 인덱스를 반환
}
int main(){
    int n, cnt=0, flag = 1; // cnt : 그룹 단어의 갯수, flag : 그룹 단어 체커(1: 그룹단어, 0: 아님)
    cin >> n; // 단어의 갯수
    
    int alphabet[26]; 
    // 0 : 아직 등장하지 않음 , 1 : 등장한 후 연속적으로 나오고 있는 상태, 2 : 연속적 등장이 끝난 상태
    string str; // 단어
    char prev;
    int index; // 각 문자의 배열 인덱스
    for(int i=0; i<n; i++){
        for(int i=0; i<26; i++) alphabet[i] = 0; // 0으로 초기화
        cin >> str;
        flag = 1;
        for(size_t i=0; i<str.length(); i++){
            index = toNumber(str[i]);
            if(i == 0) {
                prev = str[i];
                alphabet[index] = 1;
            }
            else if(alphabet[index] == 0) {
                alphabet[index] = 1; // 새로운 문자에 대해 연속적 등장이 시작되었음을 표기
                alphabet[toNumber(prev)] = 2; // 이전 문자에 대해 연속적 등장이 끝났음을 표기
                prev = str[i];
            }
            else if(alphabet[index] == 1){ // 연속 등장하고 있는 상태
                prev = str[i];
            }
            else if(alphabet[index] == 2) {// 이전에 끝난 문자가 다시 등장 : 현재 단어는 그룹 단어가 아니다
                flag = 0;
                continue;
            } 
        }
        if(flag == 1) cnt++; 
    }
    cout << cnt;
    return 0;