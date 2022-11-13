#include <bits/stdc++.h>
using namespace std;
void MergeSortedIntervals(vector<string>& v, int s, int m, int e) {

	vector<string> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i].size() <= v[j].size()) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}

	}
    
	while (i <= m) {
		temp.push_back(v[i]);
		i++;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		j++;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}
void MergeSort(vector<string>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}
int main() {
    int n;cin >> n;
    vector<vector<string>> vec;
    for(int i = -1; i < n - 1; i++){
        string str;
        if(i == -1)
            getline(cin,str);
        vector<string> s;
        getline(cin,str);
        stringstream x(str);
        while(getline(x,str,' ')){
            s.push_back(str);
        }
        vec.push_back(s);
        s.clear();
    }
    for(int i = 0; i < n; i++){
        MergeSort(vec[i], 0, vec[i].size() - 1);
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }
}