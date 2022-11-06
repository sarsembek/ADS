#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int>v;
void push(int x){
    v.push_back(x);
}
void del(){
    v.pop_back();
}
int getcur(){
    return v[v.size()-1];
}
int getmax(){
    int mx = -10000;
    for(int i=0;i<v.size();i++){
        if(v[i]>mx){
            mx = v[i];
        }
    }
    cout<< mx << endl;
}
int main(){
    cin>>n;
    while(n--){
        string s;cin>>s;
        if(s=="add"){
            cin>>x;
            push(x);
        }
        else if(s=="delete"){
            if(v.size())
                del();
        }
        else if(s=="getcur"){
            if(v.size())
                cout<< getcur() << endl;
            else
                cout<< "error" << endl;
        }
        else if(s=="getmax"){
            if(v.size())
                getmax();
            else
                cout << "error" << endl;
        }
    }
}