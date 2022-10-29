#include <bits/stdc++.h>
using namespace std;
#define MAX 2*100001
#define ll long long
ll a[4*MAX];
ll m = 0;
void heapify_up(ll ind){
    while(a[ind]>a[ind/2] && ind != 1){
        swap(a[ind],a[ind/2]);
        ind = ind/2;
    }
}
void heapify_down(ll ind){
    ll best = ind;
    if(ind * 2 <= m && a[ind*2] > a[best])
        best = ind*2;
    if(ind*2 + 1 <= m && a[ind*2 + 1] > a[best])
        best = ind*2+1;
    if(best != ind){
        swap(a[ind],a[best]);
        heapify_down(best);
    }
}
void insert(ll x){
    m++;
    a[m] = x;
    heapify_up(m);
}
ll get_max(){
    return a[1];
}
void extract_max(){
    swap(a[1],a[m]);
    m--;
    heapify_down(1);
}
ll n,x,j;
int main(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>j;
        insert(j);
    }
    ll ans = 0;
    while(x--){
        ans += get_max();
        a[1]--;
        heapify_down(1);
    }
    cout<<ans;
}
