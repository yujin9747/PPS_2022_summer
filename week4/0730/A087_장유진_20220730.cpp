/*
Maximum Units on Truck
https://leetcode.com/problems/maximum-units-on-a-truck/
*/
#include <vector>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] > b[1];
}
class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ret = 0;
        int currBox = 0;
        // 한 박스를 실을 때 가장 많은 유닛을 얻을 수 있는 순서대로 정렬(내림차순)
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for(int i=0; i<boxTypes.size(); i++){
            if(currBox + boxTypes[i][0] > truckSize) {
                ret += (truckSize-currBox) * boxTypes[i][1];
                break;
            }
            currBox += boxTypes[i][0];
            ret += boxTypes[i][0] * boxTypes[i][1];
        }
        return ret;
    }
};