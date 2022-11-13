#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
#define forj(m) for(int j=0;j<m;j++)
#define ll long long
ll n,m;
bool cmp(pair<ll,ll> p1, pair<ll,ll> p2){
    if(p1.second > p2.second)return true;
    return false;
}
void sortirovka(vector<pair<ll,ll>> &v){
    sort(v.begin(),v.end(),cmp);
}
int main(){
    cin >> n >> m;
    ll a[n][m];
    vector<pair<ll,ll>> v;
    fori(n){
        ll sum = 0;
        forj(m){
            cin >> a[i][j];
            sum += a[i][j];
        }
        v.push_back(make_pair(i,sum));
    }
    sortirovka(v);
    ll tmp[n][m];
    fori(n){
        forj(m){
            tmp[i][j] = a[v[i].first][j];
        }
    }
    fori(n){
        forj(m){
            for(int l=i+1;l<n;l++){
                if(v[i].second <= v[l].second){
                    if(tmp[i][0] < tmp[l][0])
                        i++;
                    if(tmp[i][j]>tmp[l][j]){
                        for(int k=0;k<m;k++){
                            ll tp;
                            tp = tmp[l][k];
                            tmp[l][k] = tmp[i][k];
                            tmp[i][k] = tp;
                        }
                    }
                }
            }
        }
    }
    /*
    fori(n){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    */
    fori(n){
        forj(m){
            cout << tmp[i][j] << ' ';
        }
        cout << endl;
    }
}