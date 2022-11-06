#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll q,n,k,cnt = 0;
deque<ll> deq_1;
deque<ll> deq_2;
int main(){
    cin >> q;
    while(q--){
        cin >> n;
        if(n == 1){
            cin >> k;
            if(cnt % 2 == 0){
                deq_1.push_front(k);
                deq_2.push_back(k);
            }
            else{
                deq_1.push_back(k);
                deq_2.push_front(k);
            }
        }
        if(n == 2){
            cnt++;
        }
    }
    if(cnt%2==1){
        for(int i=0;i<deq_1.size();i++){
            cout<<deq_1[i]<<' ';
        }
    }
    else{
        for(int i=0;i<deq_2.size();i++){
            cout<<deq_2[i]<<' ';
        }
    }
}