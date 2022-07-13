/*
미완
이진 탐색 트리
https://www.acmicpc.net/problem/5639
*/
#include <iostream>
/*
50 30 24 5 28 45 98 52 60
*/
using namespace std;
class Node{
    public:
        int key;
        Node* left;
        Node* right;
    public:
        Node(int k):key(k), left(nullptr), right(nullptr){}
        void postOrder(){
            if(this->left != nullptr) this->left->postOrder();
            if(this->right != nullptr) this->right->postOrder();
            cout << this->key << "\n";
        }
        Node* insert(Node* newNode){
            Node* ret;
            if(this == nullptr) ret = newNode;
            if(this->key > newNode->key) ret = this->left->insert(newNode);
            else if(this->key < newNode->key) ret = this->right->insert(newNode);
            return ret;
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int key; // key 값은 양의 정수
    Node* head;  
    
    // stage 1. 전위 순회값을 통해 tree 구성하기
    while(cin >> key){
        if(key == EOF) break;
        Node* newNode = new Node(key);
        head = head->insert(newNode);
    }
    
    // stage 2. 후위 순회값 출력하기
    head->postOrder();
    return 0;
}