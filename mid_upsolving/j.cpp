#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(i = 0;i < n;i++)
#define ll long long
#define mp make_pair
#define pb push_back
#define MAX 100001
int i,j,n,k,t;
int a[MAX];
bool flag = false;
int bs(int l,int r,int val){
    while(r >= l){
        int mid = (r+l)/2;
        if(a[mid] + val == k){  
            flag = true;
            return a[mid];
        }
        else if(a[mid] + val > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main(){
    cin >> k >> n;
    fori(n){
        cin >> a[i];
    }
    sort(a,a+n);
    fori(n){
        t = bs(i + 1,n - 1,a[i]);
        if(t != -1 and flag){
            cout << a[i] << ' ' << t;
            return 0;
        }
    }
}
