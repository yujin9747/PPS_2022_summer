/*
Next Greater Element 1
https://leetcode.com/problems/next-greater-element-i/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int foundFlag;  // 0: 아직 같은 숫자를 찾지 못함, 1: 찾음, 2: 바로 오른쪽의 큰 숫자를 찾음
        for(int i=0; i<nums1.size(); i++){  
            foundFlag = 0;                  // 새로운 nums1안의 숫자에 대해 nums2에서 찾지 못했음을 표기
            for(int j=0; j<nums2.size(); j++){
                if(foundFlag == 0){         // 아직 찾지 못한 경우 
                    if(nums1[i] == nums2[j]) foundFlag = 1; // 숫자 비교 후 같으면 foundFlag = 1
                }
                else{                       // 찾은 경우
                    if(nums1[i] < nums2[j]) {   // 오른쪽의 숫자 중 nums1[i]보다 큰 것을 찾는다
                        nums1[i] = nums2[j];    // 큰 숫자를 찾았다면 nums1[i]에 저장
                        foundFlag = 2;          
                        break;                  // j를 더이상 증가시키지 않고 for문을 종료한다
                    }       
                } 
            }
            if(foundFlag == 1) nums1[i] = -1;   // 숫자는 찾았지만 더 큰 오른쪽의 숫자를 찾지 못한 경우 -1
        }
        return nums1;                           // 완성된 nums1을 반환한다
    }
};