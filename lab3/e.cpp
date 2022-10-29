#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 2 * 100001
int n,k,i,j;
struct coord{
    int x1,y1,x2,y2;
};
coord a[MAX];

bool check(int x){
    int cnt = 0;
    fori(n){
        if(a[i].x2 <= x and a[i].y2 <= x){
            cnt++;
        }
    }
    return k <= cnt;
}

int bs(){
    int l = 0;
    int r = 1000000001;
    int mid;
    while(true){
        mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else   
            l = mid;
        if(r-l == 1)
            return r;
    }
} 

int main(){
    cin >> n >> k;
    fori(n)
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    cout << bs();
}