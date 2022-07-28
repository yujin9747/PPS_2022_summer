/*
Height Checker
https://leetcode.com/problems/height-checker/
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a > b;   // 오름차순 정렬
    }
};
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ret = 0;
        priority_queue<int, vector<int>, cmp> q;
        for(int i=0; i<heights.size(); i++){    // heights를 오름차순 정렬해 queue에 넣는다
            q.push(heights[i]);
        }
        for(int i=0; i<heights.size(); i++){    // queue와 hieghts의 같은 위치를 비교한다
            if(heights[i] != q.top()) ret++;    // 숫자가 다르면 return 값을 증가한다
            q.pop();                            // 비교한 숫자를 제거한다
        }
        return ret;
    }
};