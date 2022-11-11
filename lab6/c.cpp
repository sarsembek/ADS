#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low, int high){
    int piv = arr[high];
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
void quickSort(int arr[], int low,int high){
    if(low < high){
        int piv = partition(arr, low,high);
        quickSort(arr,low,piv-1);
        quickSort(arr, piv+1,high);
    }

}
vector <pair<int,int>> ans;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    quickSort(a, 0, n-1);
    int least = 1e9;
    for(int i = 0; i < n; i++){
        if(abs(a[i] - a[i + 1]) < least){
            least = abs(a[i] - a[i + 1]);
            ans.clear();
            ans.push_back(make_pair(a[i],a[i + 1]));
        }
        else if(abs(a[i] - a[i + 1]) == least){
            ans.push_back(make_pair(a[i],a[i + 1]));
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << ' ' << ans[i].second << ' ';
    }
}