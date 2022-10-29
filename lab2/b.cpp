#include<iostream>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 2501
ll i,j;
struct node{
    string data;
    node *nxt = NULL;
    node() {
        data = "";
    }
    node(string _data,node * _nxt){
        data = _data;
        nxt = _nxt;
    }
};
struct linked_list{
    node *head,*tail;
    linked_list(){
        head = new node("",NULL);
        tail = new node("",NULL);
    }
    void output(){
        node *cur = head;
        while(cur != NULL){
            cout << cur->data << " ";
            cur = cur->nxt; 
        }
        cout << "\n";
    }
    void insert_end(string data){
        if(head->data == ""){
            head->data = data;
            tail = head;
        }else{
            node *new_node = new node(data,NULL);
            tail->nxt = new_node;
            tail = new_node; 
        }
    }
    node* get_tail(){
        node *cur = head;
        while(cur->nxt != NULL){
            cur = cur->nxt;  
        }
        return cur;
    }
    void pop_front(){
        head = head->nxt;
    }
    void cyclicShift(int k){
        string front;
        while(k--){
            front = head->data;
            pop_front();
            insert_end(front);
        }
    }
};
int main(){
    linked_list l; 
    int n;cin >> n;
    int k;cin >> k;
    string s;
    fori(n){
        cin >> s;
        l.insert_end(s);
    }
    l.cyclicShift(k);
    l.output();
}