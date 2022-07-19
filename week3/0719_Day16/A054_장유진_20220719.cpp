
/*
크레인 인형뽑기 게임
https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector <vector<int> > board, vector<int> moves) {
    int answer = 0, item, flag;
    int N = board[0].size();                    // N*N 격자
    stack<int> basket;                          // 집은 인형을 담을 바구니
    
    for(int i=0; i<moves.size(); i++){          // 인형 집게를 move 하고자 하는 모든 위치에 대해 수행한다
        for(int j=0; j<N; j++){                 // 해당 위치에서 아래로 한 칸씩 내려가며 top에 있는 인형을 집는다
            flag = 0;
            item = board[j][moves[i]-1];
            if(item != 0){                      // top 인형을 찾은 경우
                flag = 1;                       // flag 변수 수정
                if(!basket.empty() && basket.top() == item){    // 바스켓의 최상위 인형과, 현재 뽑는 인형이 같은 경우
                    answer += 2;                // 현재 뽑는 인형, 바스켓의 최상위 인형 두 개를 삭제하므로 +2
                    basket.pop();               // 바스켓에서 하나 삭제
                }
                else basket.push(item);         // 바스켓이 비어 있는 경우 push
                board[j][moves[i]-1] = 0;       // pick up 한 인형 삭제
            }
            if(flag == 1) break;                // 인형을 찾아 바구니에 담은 후, 다음 move 명령을 이행하기 위해 break;  
                                                // 인형이 없는 경우 아래 칸으로 이동한다
        }
    }
    return answer;
}

int main(){
    /* vector< vector<int> > board = {{0,0,0,0,0}, 
                                      {0,0,1,0,3}, 
                                      {0,2,5,0,1}, 
                                      {4,2,4,4,2}, 
                                      {3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};*/
    vector< vector<int> > board ;
    vector<int> moves;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);

    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(0);
    temp.push_back(3);
    board.push_back(temp);

    temp.clear();
    temp.push_back(0);
    temp.push_back(2);
    temp.push_back(5);
    temp.push_back(0);
    temp.push_back(1);
    board.push_back(temp);

    temp.clear();
    temp.push_back(4);
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(4);
    temp.push_back(2);
    board.push_back(temp);

    temp.clear();
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(1);
    board.push_back(temp);

    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(1);
    moves.push_back(4);
    cout << solution(board, moves);
    return 0;
}