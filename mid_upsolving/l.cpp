#include <bits/stdc++.h>
using namespace std;
#define MAX 2501
int cnt = 0;
struct node{
    node *left,*right;
    int key;
    node(int _key){
        key = _key;
        left = right = NULL;
    }
    node(int key,node* left, node* right)
    :key(key),left(left),right(right){};
};
struct BST{
    node* root;
    BST(){
        root = NULL;
    }
    void insert(int x,node* cur){
        node* next = NULL;
        if(root == NULL){
            root = new node(x);
            return;
        }
        else if(x <= cur->key){
            if(cur->left == NULL){
                cur->left = new node(x);
                return;
            }
            next = cur->left;
        }
        else{
            if(cur->right == NULL){
                cur->right = new node(x);
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
        if(nd == NULL){
            return;
        }
        print(nd->left);
        cout<<nd->key<<' ';
        print(nd->right);
    }
    void nochild(node *cur){
        if(cur == NULL){
            return;
        }
        if(cur->left == NULL&&cur->right == NULL){
            cnt++;
        }
        if(cur->left != NULL){
            nochild(cur->left);
        }
        if(cur->right != NULL){
            nochild(cur->right);
        }
    }
    void solution(){
        nochild(root);
    }
};
int n,k,j;
int main(){
    BST b;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> j;
        b.insert(j);
    }
    b.solution();
    cout << cnt;
}