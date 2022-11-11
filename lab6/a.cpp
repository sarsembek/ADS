#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
int partition(string &s,int l,int r){
    int pivot = s[r];
    int i = l - 1;
    for(int j=l;j<r;j++){
        if(s[j] <= pivot){
            i++;
            swap(s[i],s[j]);
        }
    }
    swap(s[i + 1],s[r]);
    return i + 1;
}
void quickSort(string &s,int l,int r){
    if(l < r){
        int piv = partition(s,l,r);
        quickSort(s,l,piv - 1);
        quickSort(s,piv + 1,r);
    }
}
string s1,s2,vowels = "aeiou";
char k;
int n;
int main(){
    cin >> n;
    s1 = "";s2 = "";
    while(n--){
        cin >> k;
        if(vowels.find(k) != -1)
            s1 += k;
        else
            s2 += k;
    }
    quickSort(s1,0,s1.size() - 1);
    quickSort(s2,0,s2.size() - 1);
    cout << s1 + s2;
}