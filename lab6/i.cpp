#include <bits/stdc++.h>
using namespace std;
int partition(string &s,int low, int high){
    char piv = s[high];
    int i = low-1;
    for(int j = low ; j < high; j++){
        if(s[j] <= piv){
            i++;
            swap(s[i], s[j]);
        }
    }
       swap(s[i+1], s[high]);
       return i+1;

}
void quickSort(string &s, int low,int high){
    if(low < high){
        int piv = partition(s, low,high);
        quickSort(s,low,piv-1);
        quickSort(s, piv+1,high);
    }
}
int main(){
    string s;cin >> s;
    quickSort(s,0,s.size()-1);
    cout << s;
}