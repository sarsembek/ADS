#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define ll long long
int partition(ll *s,ll l,ll r){
    ll pivot = s[r];
    ll i = l - 1;
    for(int j=l;j<r;j++){
        if(s[j] <= pivot){
            i++;
            swap(s[i],s[j]);
        }
    }
    swap(s[i + 1],s[r]);
    return i + 1;
}
void quickSort(ll *s,ll l,ll r){
    if(l < r){
        ll piv = partition(s,l,r);
        quickSort(s,l,piv - 1);
        quickSort(s,piv + 1,r);
    }
}
int main(){
    ll n,m;
    cin >> n>> m;
    ll a[n];
    ll b[m];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }
    quickSort(a, 0, n-1);
    quickSort(b,0,m-1);
    vector <ll> v(n+m);
    vector <ll> :: iterator i,j;
    i = set_intersection(a, a+n, b, b+m, v.begin());
        for (j = v.begin(); j != i; j++){
        cout << *j << " ";
    }
}