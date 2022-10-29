#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int main(){
    deque<int>b,n;
    int cnt=0;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<5;i++){
        int y;
        cin>>y;
        n.push_back(y);
    }
    while((!b.empty()&&!n.empty())&&cnt<pow(10,6)){
        if(((b.front()>n.front())&&(b.front()!=9||n.front()!=0))||(b.front()==0&&n.front()==9)){
            b.push_back(b.front());
            b.pop_front();
            b.push_back(n.front());
            n.pop_front();
            cnt++;
        }
        else{
            n.push_back(b.front());
            b.pop_front();
            n.push_back(n.front());
            n.pop_front();
            cnt++;
        }
    }
    if(cnt==pow(10,6)){
        cout<<"blin nichya";
    }
    else if(b.empty()){
        cout<<"Nursik "<<cnt;
    }else{
        cout<<"Boris "<<cnt;
    }
}