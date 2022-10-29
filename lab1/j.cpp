#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    int cnt = 0;
    deque<int> dq;
    char a;
    int num;
    bool t = true;
    while(t){
        cin >> a;
        if(a == '+'){
            cin >> num;
            dq.push_front(num);
        }
        if(a == '-'){
            cin >> num;
            dq.push_back(num);
        }
        if(a == '*'){
            if(dq.size()==1){
                v.push_back(dq.front() + dq.back());
                dq.pop_back();
            }
            else if(!dq.empty()){
                v.push_back(dq.front() + dq.back());
                dq.pop_front();
                dq.pop_back();
            }else{
                v.push_back(-1);
            }
        }
        if(a == '!'){
            t = false;
        }
    }for(int i:v){
        if(i!=-1){
            cout<<i<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
}