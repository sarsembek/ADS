#include <bits/stdc++.h>
#define fori(n) for(i = 0;i < n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define ll long long
#define str string

using namespace std;

struct Student
{
    str string1, string2;
	str arg;
	double gpa;
};



bool cmp(const Student &a, const Student &b){
    if (a.gpa < b.gpa)return true;
    if (a.gpa == b.gpa && a.string1 < b.string1)return true;
    if (a.gpa == b.gpa && a.string1 == b.string1 && a.string2 < b.string2)return true;
    return false;
}

void sortirovka (Student arr[], ll n){
    sort(arr, arr+n, cmp);
}

double Gpashka(str l){
	str ocenka[] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};
	// double d[] = {4, 3.75, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0};

	double d[] = {4, 3.75, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0};
    int i = 0 ;
	fori(sizeof(ocenka)){
		if(l == ocenka[i]) return d[i];
	}
	return 0;
}

int main(){
	int n, m;
	cin>>n;
	Student stac[n];
	deque<deque<string>> deq;
	deque<deque<int>> deqdeq;
    int i = 0 ;
	fori(n){

		cin>>stac[i].string1>>stac[i].string2>>m;
		str l;
		ll num;
	    deque<string> d;
	    deque<int> dd;
        ll j =0;
		forj(m){
			cin>>l>>num;
			d.push_back(l);
			dd.push_back(num);
		}
		deq.push_back(d);
		deqdeq.push_back(dd);
	}
	fori(n){
		double sum1 = 0;
		double sum2 = 0;
        int j= 0;
		forj(deq[i].size()){
			double l = Gpashka(deq[i][j]);
			sum1 = sum1 + l*deqdeq[i][j];
			sum2 = sum2 + deqdeq[i][j];
			//cout<<l<<" "<<sum1<<" "<<sum2<<endl;
		}
		stac[i].gpa = sum1/sum2;
	}
	int nn = sizeof(stac)/sizeof(stac[0]);

    sortirovka(stac, nn);
    
    fori(n){
        cout<<stac[i].string1<<" "<<stac[i].string2<<" "<<fixed<<setprecision(3)<<stac[i].gpa<<endl;
    }
}