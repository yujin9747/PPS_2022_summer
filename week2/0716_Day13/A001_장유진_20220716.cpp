/*
Assign cookies
https://leetcode.com/problems/assign-cookies/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret=0;

        // 오름차순 정렬
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // g의 가장 작은 사이즈 부터, s의 가장 작은 사이즈 부터 점점 커지며 assgin 가능한 쿠키 찾기
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(g[i] <= s[j]) {
                    ret++;
                    for(int k=0; k<=j; k++) s.erase(s.begin());  // j번째 쿠키보다 앞선 쿠키는 size가 더 작기 때문에 다음 child의 size를 충족시킬 수 없으니 삭제한다.
                    break;                                       // 다음 child에 대한 반복 시작
                }
            }
        }
        return ret;
    }
};

int main(){
    vector<int> g;
    vector<int> s;

    /* Test #1
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    s.push_back(1);
    s.push_back(1);

    Solution solution;
    int result = solution.findContentChildren(g, s);
    cout << result; // 1 expected
    */

    /* Test #2
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    s.push_back(3);

    Solution solution;
    int result = solution.findContentChildren(g, s);
    cout << result; // 1 expected
    */

    /* Test #3
    g.push_back(10);
    g.push_back(9);
    g.push_back(8);
    g.push_back(7);
    s.push_back(10);
    s.push_back(9);
    s.push_back(8);
    s.push_back(7);

    Solution solution;
    int result = solution.findContentChildren(g, s);
    cout << result; // 4 expected
    */

    /* Test #4
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);

    Solution solution;
    int result = solution.findContentChildren(g, s);
    cout << result; // 0 expected
    */

    /* Test #5
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    s.push_back(3);

    Solution solution;
    int result = solution.findContentChildren(g, s);
    cout << result; // 1 expected
    */

    return 0;
}


/*
sort 방식 사용하기 전, 사용했던 코드
-> time limit exceed 발생 : 매번 optimalGap을 찾아야 하기 때문에 vector의 사이즈가 크면 클수록 시간 복잡도가 커진다.

        // s[i] >= g[i] 인 경우 assign 가능 
        // 하나의 쿠키를 assign 함으로써 한 명의 아이가 content 해야 하는 최소 사이즈를 충족시켜야 한다.
            int ret = 0;
        for(int i=0; i<g.size(); i++){                  // children마다 검사
            int optimalGap = optimalGap = *max_element(s.begin(), s.end()) - *min_element(g.begin(), g.end()) + 1;  // 도출될 수 있는 최대 gap+1으로 초기화(비교 후 update될 것)
            int optimal_index = -1;                     // gap이 가장 적은 쿠키 인덱스
            for(int j=0; j<s.size(); j++){              // s 중 하나의 쿠키를 assign 할 수 있는지 검사
                if(s[j] >= g[i]){                       // assign 가능
                    if(j == 0) {                        // optimal 초기 값 설정
                        optimalGap = s[j]-g[i]; 
                        optimal_index = 0;
                    }
                    else if(s[j]-g[i] < optimalGap) {   // gap이 가장 작은 쿠키를 update하며 반복문 진행
                        optimalGap = s[j]-g[i];
                        optimal_index = j;
                    }
                }
            }
            if(optimal_index != -1){                    // assgin 가능한 쿠키가 존재하는 경우
                ret++;
                s.erase(s.begin()+optimal_index);       // assign된 쿠키 삭제
                if(s.size() == 0) return ret;
            } 
        }
        return ret;
*/
