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
void heapifyup(ll ind){
    while(a[ind] < a[ind/2] && ind != 1){
        swap(a[ind],a[ind/2]);
        ind = ind/2;
    }
}
void heapifydown(ll ind){
    ll best = ind;
    if(ind*2 <= n && a[ind*2] < a[best])
        best = ind*2;
    if(ind*2 + 1 <= n && a[ind*2+1] < a[best])
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
ll get_min2(){
    if(n >= 3){
        if(a[2]<=a[3])
            return a[2];
        else
            return a[3];
    }
    if(n < 3)
        return a[2];
}
void extract_min(){
    swap(a[1],a[n]);
    n--;
    heapifydown(1);
}
ll i,j,m,x;
int main(){
    cin>>x>>m;
    fori(x){
        cin>>j;
        insert(j);
    }
    int cnt = 0;
    while(get_min()<=m && n >= 2){
        insert(get_min() + 2*get_min2());
        extract_min();
        extract_min();
        cnt++;
    }
    if(n<=2 && a[1] <= m)
        cout<<-1;
    else
        cout<<cnt;
}