#include <bits/stdc++.h>
using namespace std;
int partition(vector <int> &v,int low, int high){
    int piv = v[high];
    int i = low-1;
    for(int j = low ; j < high; j++){
        if(v[j] <= piv){
            i++;
            swap(v[i], v[j]);
        }
    }
       swap(v[i+1], v[high]);
       return i+1;

}
void quickSort(vector <int> &v, int low,int high){
    if(low < high){
        int piv = partition(v, low,high);
        quickSort(v,low,piv-1);
        quickSort(v, piv+1,high);
    }

}
int parseDate(const std::string &s){
    int month,day,year;
    if(std::sscanf(s.c_str(),"%d-%d-%d", &day, &month, &year) != 3){

    } else{
        return 10000 * year + 100 * month + day;
    }
}
int main(){
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0 ; i < n;i++){
        string s;
        cin >> s;
        v.push_back(parseDate(s));
    }
    quickSort(v,0,v.size()-1);
    for(int i = 0 ; i<= v.size()-1;i++){
      cout << setfill('0') << setw(2) << v[i]%100<< "-";
      cout << setfill('0') << setw(2) << (v[i] /100)%100 <<"-";
      cout << v[i] /10000 << endl;
    }
}
