/*
시간초과
연결 요소의 개수
https://www.acmicpc.net/problem/11724
*/
#include <iostream>
#include <vector>

using namespace std;

typedef struct vertex{
    int val;
    vertex* next;
    int check;
    vertex(){};
    vertex(int v):val(v), next(nullptr), check(0){}
}vertex;

void check_OneCC(vertex* v[], int i){
    vertex* curr = v[i];
    if(curr->check == 0) curr->check = 1;
    else return;
    while(1){
        curr = curr->next;
        if(curr == nullptr) return;
        check_OneCC(v, curr->val - 1);
    }
}
int main(){
    int n, m, u, v;
 
    cin >> n >> m;
    vertex* vertices[n];

    for(int i=0; i<n; i++) vertices[i] = nullptr;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        vertex* from = new vertex(u);
        vertex* end = new vertex(v);

        if(vertices[u-1] == nullptr){
            from->next = end;
            end->next = nullptr;
            vertices[u-1] = from;
        }
        else{
            vertex* curr = vertices[u-1];
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = end;
            curr->next->next = nullptr;
        }

        vertex* from2 = new vertex(v);
        vertex* end2 = new vertex(u);
        if(vertices[v-1] == nullptr){
            from2->next = end2;
            end2->next = nullptr;
            vertices[v-1] = from2;
        }
        else{
            vertex* curr = vertices[v-1];
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = end2;
            curr->next->next = nullptr;
        }
    }
    int CC=0;
    for(int i=0; i<n; i++){
        if(vertices[i]->check == 0) {
            CC++;
            check_OneCC(vertices, i);
        }
    }
    cout << CC ;
    return 0;
}