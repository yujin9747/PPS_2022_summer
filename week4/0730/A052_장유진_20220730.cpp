/*
OX 퀴즈
*/
#include <iostream>
using namespace std;
int main(){
    int n, m, sum; 
    cin >> n;
    char ox[n];
    for(int i=0; i<n; i++){
        m=0;
        sum=0;
        cin >> ox;
        int j=0;
        while(ox[j]){
            if(ox[j] == 'X') m = 0;
            else if(ox[j] == 'O'){
                m++;
                sum += m;
            }
            j++;
        }
        cout << sum << "\n";
    }
    return 0;
}