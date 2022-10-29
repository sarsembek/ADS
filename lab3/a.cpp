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
ll n,m,t,i,j;
ll q[10001];
vector<ll> a[1000];
pair<bool,ll> bs(vector<ll> v,ll l,ll r,ll x){
    ll mid;
    while(true){
        mid = (l+r)/2;
        if(v[mid] > x)
            r = mid-1;
        else if(v[mid] < x) 
            l = mid + 1;
        else 
            return mp(true,mid);
        if(l > r)
            return mp(false,-1);
    }   
}
pair<bool,ll> bs_rev(vector<ll> v,ll l,ll r,ll x){
    ll mid;
    while(true){
        mid = (l+r)/2;
        if(v[mid] > x)
            l = mid+1;
        else if(v[mid] < x) 
            r = mid-1;
        else 
            return mp(true,mid);
        if(l > r)
            return mp(false,-1);
    }   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    fori(t)
        cin >> q[i];
    cin >> n >> m;
    fori(n)
        forj(m){
            ll x;cin >> x;
            a[i].push_back(x);
        }
    forj(t){
        bool flag = false;
        fori(n){
            pair<bool,ll> ch;
            if(i % 2==0){
                if(a[i][0] >= q[j] and a[i][m-1] <= q[j]){
                    ch = bs_rev(a[i],0,m-1,q[j]); 
                }
            }
            else{
                if(a[i][m-1] >= q[j] and a[i][0] <= q[j]){
                    ch = bs(a[i],0,m-1,q[j]);;
                }
            }
            if(ch.first){
                cout << i << " " << ch.second << "\n";
                flag =true;
            }
        }
        if(!flag)
                cout << -1 << "\n";
    }
    return 0;
}