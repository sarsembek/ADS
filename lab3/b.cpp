#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 1000001
ll n,k,i,j,a[MAX];

bool check(ll x){
    ll sum = 0;
    int cnt = 0;
    fori(n){
        if(a[i] > x)
            return false;
        if(sum + a[i] > x){
            sum = 0;
            cnt++;
        }
        sum += a[i];
    }
    cnt++;
    return cnt <= k;
}

ll bs(){
    ll l = 0;
    ll r = 19000000000;
    ll mid;
    while(true){
        mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else 
            l = mid;
        if(r - l == 1)
            return r;
    }
}
int main(){
    cin >> n >> k;
    fori(n)
        cin >> a[i];
    cout << bs();
}