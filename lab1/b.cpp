#include <iostream>
#include <stack>
using namespace std;
int main(){
    int a,n;
    cin>>n;
    int d[n];
    stack<int>st1;
    for(int i=0;i<n;i++){
        cin>>a;
        if(st1.empty()){
            st1.push(a);
            d[i]=-1;
        }
        else{
            while(!st1.empty()){
                int top = st1.top();
                if(top<=a){
                    d[i]=top;
                    break;
                }else{
                    d[i]=-1;
                    st1.pop();
                }
            }st1.push(a);
        }
    }
    for(int i=0;i<n;i++){
        cout<<d[i]<<' ';
    }
}