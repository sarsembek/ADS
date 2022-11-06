#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 2501
bool prime[MAX];
vector<int> v;
bool isPrime(int a){
    if(a == 0 or a ==1)
        return false;
    if(a == 2)
        return true;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)
            return false;
    }
    return true;
}
ll n,k;
int main(){
    for(int i=0;i<MAX;i++){
        prime[i] = true;
    }
    cin >> n;
    k = sqrt(n);
    int cnt = 0;
    for(int j = 2;j <= k;j++){
        if(n % j == 0){
            if(isPrime(j))
                cnt++;
            if((n/j) != j and isPrime(n/j))
                cnt++;
        }
    }
    cout << cnt;
}