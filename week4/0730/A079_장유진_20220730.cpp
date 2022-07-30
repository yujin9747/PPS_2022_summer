/*
K번째 수
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sorted;
    for(int i=0; i<commands.size(); i++){
        for(int j=commands[i][0]; j<=commands[i][1]; j++){
            sorted.push_back(array[j-1]);
        }
        sort(sorted.begin(), sorted.end());
        answer.push_back(sorted[commands[i][2]-1]);
        sorted.clear();
    }
    return answer;
}