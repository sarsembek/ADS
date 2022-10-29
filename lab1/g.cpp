#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int number){
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0,cnt=0;cnt<=n;i++){
        if(isPrime(i)){
            cnt++;
            v.push_back(i);
            if(cnt==n){
                break;
            }
        }
    }
    for(int i=v.at(n-1)+1,cnt=0;cnt<=v.at(n-1);i++){
        if(isPrime(i)){
            cnt++;
            v.push_back(i);
            if(cnt==v.at(n-1)){
                break;
            }
        }
    }
    cout<<v.at(v.at(n-1)-1);
}