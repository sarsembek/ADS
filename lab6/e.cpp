#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(i = 0;i < n;i++)
#define forj(n) for(j = 0;j < n;j++)
int partition(int arr[],int low, int high){
    int piv = arr[high];
    int i = low-1;
    for(int j = low ; j < high; j++){
        if(arr[j] >= piv){
            i++;
            swap(arr[i], arr[j]);
        }
    }
       swap(arr[i+1], arr[high]);
       return i+1;

}
void quickSort(int arr[], int low,int high){
    if(low < high){
        int piv = partition(arr, low,high);
        quickSort(arr,low,piv-1);
        quickSort(arr, piv+1,high);
    }
}
int main(){
    int i = 0,j = 0;
    int n,m;
    cin >> n >> m;
    int a[n][m];
    int tr[m][n];
    fori(n){
        forj(m){
            cin >> a[i][j];
            tr[j][i] = a[i][j];
        }
    }
    fori(n){
        forj(m){
            tr[j][i] = a[i][j];
        }
    }
    forj(m){
        quickSort(tr[j],0,n-1);
    }
    fori(m){
        forj(n){
            a[j][i] = tr[i][j];
        }
    }
    fori(n){
        forj(m){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}