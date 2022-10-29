#include <iostream>
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
    for(int i=0,cnt=0;cnt<=n;i++){
        if(isPrime(i)){
            cnt++;
            if(cnt==n){
                cout<<i;
                return 0;
            }
        }
    }
}