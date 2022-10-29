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
int n,k,a[MAX],i,j;

bool check(int x){
    int f = 0;
    double p;
    fori(n){
        p = a[i];
        p = p / x;
        f += ceil(p);
    }
    return f <= k;
}

int bs(int mx){
    int left = 0;
    int right = mx;
    int mid;
    while(true){
        mid = (right + left)/2;
        if(check(mid)){
            right = mid;
        }else 
            left = mid;
        if(right - left == 1)
            return right;
    }
}
int main(){
    cin >> n >> k;
    fori(n)
        cin >> a[i];
    int mx = a[0];
    cout << bs(1000000001);
}