#include <bits/stdc++.h>
using namespace std;
struct node
{
    string data;
    node* next;
    node(){
        data = "";
    }
    node(string _data,node *_next){
        data = _data;
        next = _next;
    }
};
struct linked_list
{
    node *head,*tail;
    linked_list()
    {
        head = new node("",NULL);
        tail = new node("",NULL);
    }
    node* get_tail(){
        node* cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        return cur;
    }
    void insert_end(string _data){
        if(head->data == ""){
            head->data = _data;
            tail = head;
        }
        else{
            node *new_node = new node(_data,NULL);
            tail->next = new_node;
            tail = new_node;
        }
    }
    void pop_front(){
        head = head->next;
    }
    void cyclicShift(int k){
        string front;
        while(k--){
            front = head->data;
            pop_front();
            insert_end(front);
        }
    }
    void output()
    {
        node *cur = head;
        while(cur != NULL){
            cout << cur->data <<" ";
            cur = cur->next;
        }
        cout <<endl;
    }
};
int main()
{
    linked_list l;
    int n;cin>>n;
    int k;cin>>k;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        l.insert_end(s);
    }
    l.cyclicShift(k);
    l.output();
}