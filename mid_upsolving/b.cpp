#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 
ll n,k;
vector<int>v;
bool isPrime(int a){
    if(a==1 or a==0)
        return false;
    if(a==2)
        return true;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)
            return false;
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            if(v[i]+v[j]==n){
                cout<<v[i]<<' '<<v[j]<<endl;
                return 0;
            }
        }
    }
}