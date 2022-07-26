/*
Summary Ranges
https://leetcode.com/problems/summary-ranges/
*/
#include <iostream>
#include <vector>
class Solution {
public:
    // 자기 자신만 들어가는 경우 : 단일 범위
    // 2개 이상이 들어가는 경우
    vector<string> summaryRanges(vector<int>& nums) {
        int start, prev;
        vector<string> ret;
        stringstream ss;
        if(nums.size() == 0) return ret;    // nums가 비어 있는 경우, range는 존재하지 않는다
        for(int i=0; i<nums.size(); i++){   // 모든 숫자를 순회하며 범위를 찾는다
            if(i == 0){                 // 첫 숫자인 경우 start로 초기화 한다
                start = nums[i];
                prev = start;
                if(i == nums.size()-1) {
                    ret.push_back(to_string(start));
                    return ret; // nums에 하나의 숫자밖에 없는 경우, 단일 범위 추가 후 리턴한다
                }
            }
            else {
                if(nums[i] != prev+1){      // 이전 숫자와 연속되는 숫자가 아닌 경우 -> range에 포함되지 않음 -> 이전까지의 범위 저장
                    if(start != prev) ret.push_back(to_string(start) + "->" + to_string(prev));   // 단일 범위가 아닌 경우   
                    else ret.push_back(to_string(start));                              // 단일 범위인 경우
                    start = nums[i];                                        // 현재 숫자를 새로운 범위의 시작 점으로 설정
                    prev = nums[i];
                    if(i == nums.size()-1) {
                        ret.push_back(to_string(start));
                        return ret;     // 마지막 숫자였을 경우, 단일 범위 push 한 후, 리턴
                    }
                }
                else {                      // 이전 숫자와 연속되는 경우 -> rnage에 포함된다         
                    prev++;                 // 연속되는 현재 숫자를 prev에 대입
                    if(i == nums.size()-1) {
                        ret.push_back(to_string(start) + "->" + to_string(prev));
                        return ret;   // 마지막 숫자였을 경우 마지막 범위를 push 한 후, 리턴
                    }
                }
            }
        }
        return ret;
    }
};