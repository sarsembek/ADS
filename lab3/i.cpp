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
#define elif else if
ll n,q,t,a[MAX],i,j;
bool bs(ll l,ll r,ll x){
    ll mid;
    while(true){
        mid = (l+r)/2;
        if(a[mid] > x)
            r = mid - 1;
        else if(a[mid] < x)
            l = mid + 1;
        else
            return true;
        if(l > r)
            return false;
    }
}
int main(){
    cin >> n;
    fori1(n)
        cin >> a[i];
    cin >> q;
    (bs(1,n,q)) ? cout << "Yes\n" : cout << "No\n"; 
}