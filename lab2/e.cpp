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
    int size;
    linked_list(){
        head = new node("",NULL);
        tail = new node("",NULL);
        size = 0;
    }
    int length(){
        node *cur = head;
        while(cur != NULL){
            size++;
            cur = cur->nxt;
        }
        return size;
    }
    void output(){
        node *cur = head;
        while(cur != NULL){
            cout << cur->data << "\n";
            cur = cur->nxt;
        }
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
    
    void clear(){
        head = new node("",NULL);
        tail = new node("",NULL);     
    }
    void reverse(node *cur){
        if(cur != NULL)
            reverse(cur->nxt);
        else if(cur == NULL){
            clear();  
            return; 
        }
        insert_end(cur->data);
    }
    void solution(){
        node *nd = head;
        while(nd->nxt != NULL and nd != NULL){
            while(nd->nxt != NULL and nd->data == nd->nxt->data){
                node *nex = nd->nxt;
                nd->nxt = nex->nxt;
            }
            if(nd->nxt != NULL)
                nd = nd->nxt;
        }
    }
};
int i,j;
int main(){
    int n;cin >> n;
    string s;
    linked_list l;
    fori(n){
        cin >> s;
        l.insert_end(s);
    }
    node *nd = l.head;
    l.solution();
    l.reverse(nd);
    cout << "All in all: " << l.length() << "\nStudents:\n";
    l.output();
}