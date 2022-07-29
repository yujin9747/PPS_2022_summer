/*
틀림
https://www.acmicpc.net/problem/1463
*/
#include <iostream>
using namespace std;
int main(){
    int n, cnt=0;
    cin >> n;
    int flag=0;
    while(n != 1){
        if(n%3 == 0){
            n /= 3;
            cnt++;
            flag = 1;
            if(n%2 == 0){
                n /= 2;
                cnt++;
            }
        }
        else if(n%2 == 0 && (n-1)%3 != 0){
            n /= 2;
            cnt++;
            flag = 1;
            if(n%3 == 0){
                n /= 3;
                cnt++;
            }
        }
        if(flag == 0){
            n--;
            cnt++;
        }
        flag = 0;
    }
    cout << cnt;
    return 0;
}