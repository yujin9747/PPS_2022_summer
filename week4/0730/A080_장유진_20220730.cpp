/*
Majority Element
https://leetcode.com/problems/majority-element/
*/
#include <iostream>
#include <vector>
using namespace std;
struct element{
    int val;
    int cnt;
    element(int a):val(a), cnt(0){}
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<element> arr;
        int flag;
        for(int i=0; i<nums.size(); i++){
            flag = 0;
            for(int j=0; j<arr.size(); j++) {
                if(arr[j].val == nums[i]) {
                    flag = 1;
                    arr[j].cnt++;
                    break;
                }
            }
            if(flag == 0) {
                element e(nums[i]);
                arr.push_back(e);
            }
        }
        int max = -1, max_val;
        for(int i=0; i<arr.size(); i++){
            if(arr[i].cnt > max) {
                max = arr[i].cnt;
                max_val = arr[i].val;
            }
        }
        return max_val;
    }
};