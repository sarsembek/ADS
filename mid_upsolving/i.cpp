#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x;
int main(){
    cin >> n;
    while(n--){
        stack<ll> st;
        cin >> x;
        while(x != 0){
            if(st.empty())
                st.push(x%2);
            else if(st.top() == 0 and x%2 == 1)
                st.pop();
            else 
                st.push(x%2);
            x /= 2;
        }
        (st.empty())?cout << "YES\n":cout << "NO\n";
    }
}