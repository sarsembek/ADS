#include <iostream>
#include <deque>
#include <queue>
using namespace std;
int main(){
    int n;
    int num;
    cin>>n;
    queue<int>q;
    deque<int>dq;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    for(int i=0;i<n;i++){
        num=q.front();
        dq={q.front()};
        for(int j=1;j<q.front();j++){
            num-=1;
            dq.push_front(num);
            for(int f=0;f<num;f++){
                dq.push_front(dq.back());
                dq.pop_back();
            
            }
        }
        for(int k:dq){
            cout<<k<<" ";
        }cout<<endl;
        q.pop();
    }
}