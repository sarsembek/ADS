#include <bits/stdc++.h>
using namespace std;
int partition(vector <pair<string, string>> array, int low, int high) {
  string pivot = array[high].first;
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j].first >= pivot){
      i++;
      swap(array[i], array[j]);
      
    }
  }

  swap(array[i + 1], array[high]);
  
  return (i + 1);
}
void quickSort( vector <pair<string, string>> array, int low, int high) {
  if (low < high) {
      
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
int main(){
    int n;cin >> n;
    string old, newe;
    vector<pair<string,string>> v;
    for(int i=0;i<n;i++){
        cin >> old >> newe;
        bool ok = true;
        for(int i=0;i<v.size();i++){
            if(old == v[i].second){
                v[i].second = newe;
                ok = false;
                break;
            }
        }
        if(ok){
            v.push_back({old,newe});
        }
    }
    map<string,string> mp;
    for(int i=0;i<v.size();i++){
        mp[v[i].first] += v[i].second;
    }
    cout << mp.size() << endl;
    for(auto i : mp){
        cout<< i.first << " " << i.second<< endl;
    }
}