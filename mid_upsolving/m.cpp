#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int n = 0;
vector <int> v;
void heapifyup(int i){
    if(arr[i] > arr[i/2] and i!= 1){
        swap(arr[i], arr[i/2]);
        heapifyup(i/2);
    }

}
void heapifyup2(int i){
    if(arr[i] > arr[i/2] and i!= 1){
        swap(arr[i], arr[i/2]);
        heapifyup2(i/2);
    }
    else cout << i << endl;
}
void heapifydown(int i){
    int best = i;
    if(2*i <= n and arr[best] < arr[2*i] ) best = 2*i;
    if(2*i+1 <= n and arr[best] < arr[2*i+1]) best= 2*i +1;
    if(best != i){
        swap(arr[i], arr[best]);
        heapifydown(best);
    }
}
void push(int x){
    n++;
    arr[n] = x;
    heapifyup(n);
}
void insert(int x){
    n++;
    arr[n] = x;
}


void pop(){
    swap(arr[1], arr[n]);
    n--;
    heapifydown(1);
}

int main(){
    int a;
    cin >> a;
    for(int i = 0 ; i < a; i++){
        int d;
        cin >> d;
        push(d);
    }
    int j,g,h;
    cin >> j;
    for(int i = 0; i < j; i++){
        cin >> g >> h;
        insert(arr[g]+h);
        swap(arr[g], arr[n]);
        heapifyup2(g);
        n--;
        

     }
      for(int i = 1; i <=n; i++){
          cout << arr[i]<< " ";
      }
} 