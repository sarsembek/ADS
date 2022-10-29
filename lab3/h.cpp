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
int i,j,n,m;
int a[MAX],b[MAX],temp[MAX];
bool flag = false;
int bs(int x){
    int l = 0;
    int r = n-1;
    int m;
    int res = -1;

    while(l <= r){
        m = (l + r) / 2;

    if(x <= a[m]){
        res = m;
        r = m - 1;
    }
    else
        l = m + 1;
    }
 return res;
}

int main(){
    cin >> n >> m;
    fori(n)
        cin >> temp[i];
    fori(m)
        cin >> b[i];
    a[0] = temp[0];
    fori1(n-1){
        a[i] = a[i-1] + temp[i];
    }
    fori(m)
        cout << bs(b[i]) + 1 << "\n";
}