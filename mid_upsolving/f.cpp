#include <bits/stdc++.h>
using namespace std;
struct node{
    node *left,*right;
    int key;
    int lvl;
    node(int _key){
        left = right = NULL;
        key = _key;
    }
    node(int key,node *left,node *right)
        :key(key),left(left),right(right){}
};
int sum = 0;
struct BST{
    node *root;
    BST(){
        root = NULL;
    }
    void insert(int x,node *cur){
        node *next = NULL;
        if(root == NULL){
            root = new node(x);
            root->lvl = 0;
            return;
        }
        else if(x <= cur->key){
            if(cur->left == NULL){
                cur->left = new node(x);
                cur->left->lvl = cur->lvl + 1;
                return;
            }
            next = cur->left;
        }else{
            if(cur->right == NULL){
                cur->right = new node(x);
                cur->right->lvl = cur->lvl + 1;
                return;
            }
            next = cur->right;
        }
        insert(x,next);
    }
    void insert(int x){
        insert(x,root);
    }
    void print(node *nd){
        if(nd == NULL)
            return;
        print(nd->left);      
        cout << nd->lvl << " " << nd->key << " | ";
        print(nd->right);
    }   
    void print(){
        print(root);
    }
    void solution(node *nd){
        if(nd == NULL)
            return;
        sum += (nd->key - nd->lvl);
        solution(nd->left);
        solution(nd->right);
    }
    void solution(){
        solution(root);
    }
};
int n,j;
int main(){
    BST b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>j;
        b.insert(j);
    }
    b.solution();
    cout<<sum;
}