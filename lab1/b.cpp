#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int>q;
    int res[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
        res[i]=x;
    }
    int ans[n];
    ans[0]=-1;
    q.push(q.front());
    q.pop();
    n=1;
    while(n!=q.size()){
        if(q.front()<=res[n]){
            ans[n]=q.front();
        }else if(q.front()>res[n]){
            ans[n]=-1;
        }q.push(q.front)
        n++;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}