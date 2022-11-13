#include <bits/stdc++.h>
using namespace std;
#define fori(n) for(int i=0;i<n;i++)
void merge(int *a,int n,int *b,int m){
    vector<int> c;
    int i = 0, j = 0;
    while(i < n || j < m){
        if(i == n)
            c.push_back(b[j++]);
        else if(j == m)
            c.push_back(a[i++]);
        else if(a[i] < b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }
    assert(c.size() == n + m);
	for (int i = 0; i < n + m; i++)
		a[i] = c[i];
}
void merge_sort(int *a, int n) {
	if (n == 1)
		return;
	merge_sort(a, n / 2);
	merge_sort(a + n / 2, n - n / 2);
	merge(a, n/2, a + n / 2, n - n / 2);
}
int main(){
    int n,m;
    cin >> n>> m;
    if(n == 0 || m == 0)return 0;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    merge_sort(a,n);
    merge_sort(b,m);
    vector <int> v(n+m);
    vector <int> :: iterator i,j;
    i = set_intersection(a, a+n, b, b+m, v.begin());
        for (j = v.begin(); j != i; j++){
        cout << *j << " ";
    }
}