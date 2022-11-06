#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 2*100001
ll a[4*MAX];
ll n = 0;
ll cnt = 0;
void heapifyup(ll ind){
    while(a[ind] > a[ind/2] && ind != 1){
        swap(a[ind],a[ind/2]);
        ind = ind/2;
    }
}
void heapifydown(ll ind){
    ll best = ind;
    if(ind*2 <= n && a[ind*2] > a[best])
        best = ind*2;
    if(ind*2 + 1 <= n && a[ind*2+1] > a[best])
        best = ind*2+1;
    if(best != ind){
        swap(a[ind],a[best]);
        heapifydown(best);
    }
}

void insert(ll x){
    n++;
    a[n] = x;
    heapifyup(n);
}

ll get_min(){
    return a[1];
}

void extract_max(){
    swap(a[1],a[n]);
    n--;
    heapifydown(1);
}
void check(ll ind){
    if(a[ind*2]<a[ind*2+1] and ind*2+1<=n){
        cnt++;
    }
}
ll i,j,m,q,x,y;
int main(){
    cin >> m;
    fori(m){
        cin >> j;
        insert(j);
    }
    for(int i=1;i<=n;i++){
        check(i);
    }
    cout<<cnt;
}