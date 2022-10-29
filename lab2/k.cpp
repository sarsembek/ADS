#include<bits/stdc++.h>
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
    pair<char,bool> data;
    node *nxt = NULL;
    node *prev = NULL;
    node() {
        data.first = '0';
        data.second = false;
    }
    node(pair<char,bool> _data,node * _nxt,node *_prev){
        data = _data;
        nxt = _nxt;
        prev = _prev;
    }
};
struct linked_list{
    node *head,*tail;
    linked_list(){
        head = new node(mp('0',false),NULL,NULL);
        tail = new node(mp('0',false),NULL,NULL);
    }
    void output(){
        node *cur = head;
        while(cur != NULL){
            cout << cur->data.first << " ";
            cur = cur->nxt; 
        }
        cout << "\n";
    }
    
    void insert_end(char data){
        if(head->data.first == '0'){
            head->data.first = data;
            tail = head;
        }else{
            node *new_node = new node(mp(data,false),NULL,NULL);
            tail->nxt = new_node;
            new_node->prev = tail;
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
    void check(){
        node *cur = tail->prev;
        node *run = head;
        while(cur != NULL){
            if(cur->data.first == tail->data.first){
                tail->data.second = true;
                cur->data.second = true;
            }
            cur = cur->prev;
        }
        while(run != NULL){
            if(run->data.second == false){
                cout << run->data.first << " ";
                return;
            }
            run = run->nxt;
        }
        cout << -1 << " ";
    }  
    void clear(){
        head = new node(mp('0',false),NULL,NULL);
        tail = new node(mp('0',false),NULL,NULL);     
    } 
};
linked_list l;
int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        fori(n){
            char c;cin >> c;
            l.insert_end(c);
            l.check();
        }
        l.clear();
        cout << "\n";
    }
}