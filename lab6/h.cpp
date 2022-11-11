#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(i = 0;i < n;i++)
#define forj(n) for(j = 0;j < n;j++)
int partition(char arr[],int low, int high){
    char piv = arr[high];
    int i = low-1;
    for(int j = low ; j < high; j++){
        if(arr[j] <= piv){
            i++;
            swap(arr[i], arr[j]);
        }
    }
       swap(arr[i+1], arr[high]);
       return i+1;

}
void quickSort(char arr[], int low,int high){
    if(low < high){
        int piv = partition(arr, low,high);
        quickSort(arr,low,piv-1);
        quickSort(arr, piv+1,high);
    }
}
int i,j = 0;
int main(){
    int n;cin >> n;
    char ch[n];
    fori(n){
        cin >> ch[i];
    }
    quickSort(ch,0,n-1);
    char tg; cin >> tg;
    fori(n){
        if(ch[i]>tg){
            cout << ch[i];
            return 0;
        }
    }
    cout<< ch[0];
}