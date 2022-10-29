#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 1000001
struct node{
    node *left,*right;
    int key;
    node(int _key){
        left = right = NULL;
        key = _key;
    }
    node(int key,node *left,node *right)
        :key(key),left(left),right(right){}
};
int mx,depth[1000];
struct BST{
    node *root;
    BST(){
        root = NULL;
    }
    void insert(int x,node *cur){
        node *next = NULL;
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
        }else{
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
        if(nd == NULL)
            return;
        print(nd->left);      
        cout << nd->key << " ";
        print(nd->right);
    }   
    void print(){
        print(root);
    }
    void dfs(node *nd,int cnt = 0){
        depth[cnt] += nd->key;
        if(cnt > mx)
            mx = cnt;
        if(nd->left != NULL)
            dfs(nd->left,cnt+1);   
        if(nd->right != NULL)
            dfs(nd->right,cnt+1);
    }
};
int n,i,j;
int main(){
    cin >> n;
    BST b;
    fori(n){
        cin >> j;
        b.insert(j);
    }
    b.dfs(b.root);
    cout << mx+1 << "\n";
    for(i = 0;i <= mx;i++){
        cout << depth[i] << " ";
    }
}