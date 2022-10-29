#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
string s;
cin >> s;
deque <int> deq1;
deque <int> deq2;
for(int i = 0; i < s.size(); i++)
{
    if(s[i] == 'S'){
        deq1.push_back(i);
    }
    if(s[i] == 'K'){
        deq2.push_back(i);
    }
    
    }
    while(!deq1.empty() && !deq2.empty()){
        if(deq1.front() < deq2.front()){
            deq1.push_back(deq1.front() + s.size());
            deq1.pop_front();
            deq2.pop_front();
            continue;
        }
        else{
        deq2.push_back(deq2.front() + s.size());
        deq2.pop_front();
        deq1.pop_front();
        }
        }
        
        if(!deq1.empty()){
            
            cout << "SAKAYANAGI";
            return 0 ;
        }

        if(!deq2.empty()){
        cout << "KATSURAGI";
        return 0;
        
        }

    }