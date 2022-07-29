/*
Fairy Candy Swap
https://leetcode.com/problems/fair-candy-swap/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int totalA=0, totalB=0; 
        
        // 교환하기 전 캔디 총 갯수 구하기
        for(int i=0; i<aliceSizes.size(); i++){
            totalA += aliceSizes[i];
        }
        for(int i=0; i<bobSizes.size(); i++){
            totalB += bobSizes[i];
        }
        
        // 총 캔디 수의 차이 구하기
        int gap = totalA - totalB;
        
        // alice가 가진 캔디의 수가 더 많은 경우 1, 아닌 경우 0인 flag변수
        int largerA = 1;
        
        // bob이 가진 캔디의 수가 더 많은 경우 gap의 부호를 바꾼다
        if(gap < 0) {
            gap *= -1;
            largerA = 0;
        }

        vector<int> ret;
        // bob의 캔디가 더 많은 경우 - alice에서 작은 것을 주고, bob에서 큰 것을 줘서 gap을 메꿔야 한다
        if(largerA == 0){   
            sort(aliceSizes.begin(), aliceSizes.end()); // 오름차순 정렬
            sort(bobSizes.rbegin(), bobSizes.rend());     // 내림차순 정렬
        }// alice의 캔디가 더 많은 경우 - alice에서 큰 것을 주고, bob에서 작은 것을 줘서 gap을 메꿔야 한다
        else {
            sort(bobSizes.begin(), bobSizes.end()); // 오름차순 정렬
            sort(aliceSizes.rbegin(), aliceSizes.rend());     // 내림차순 정렬
        }
        
        for(int i=0; i<aliceSizes.size(); i++){
            for(int j=0; j<bobSizes.size(); j++){
                
                // i, j박스를 교환했을 경우 매꿀 수 있는 갭의 크기를 구한다
                int exchangeGap;
                if(largerA == 0) exchangeGap = (bobSizes[j] - aliceSizes[i])*2;
                else exchangeGap = (aliceSizes[i] - bobSizes[j])*2;
                    
                // 앞서 구한 갭을 모두 매꿀 수 있다면 두 캔디 수를 반환한다
                if(exchangeGap == gap) {
                    ret.push_back(aliceSizes[i]);
                    ret.push_back(bobSizes[j]);
                    return ret;
                }
            }
        }
              
        return ret;
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> a;
    vector<int> b;
    // int n;
    // for(int i=0; i<atoi(argv[1]); i++){
    //     cin >> n;
    //     a.push_back(n);
    // }
    // for(int i=0; i<atoi(argv[2]); i++){
    //     cin >> n;
    //     b.push_back(n);
    // }
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    b.push_back(2);
    b.push_back(4);
    vector<int> ret = s.fairCandySwap(a, b);
    cout << "Result : [" << ret[0] << ", " << ret[1] << "]\n";
    return 0;
}