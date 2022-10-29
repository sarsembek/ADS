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
node *need = NULL;
int mx = 1,a[1001];
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
    void input(node *nd,int x){
        if(nd->key == x){
            need = nd;
            return;
        }else{
            if(nd->left != NULL)
                input(nd->left,x);
            if(nd->right != NULL)
                input(nd->right,x);
        }
    }
    void solution(node *nd,int cnt = 0){
        a[cnt]++;
        if(a[cnt] > mx)
            mx = a[cnt];
        if(nd->left != NULL)
            solution(nd->left,cnt+1);
        if(nd->right != NULL)
            solution(nd->right,cnt+1);
    }
};
int n,x,y,z,i,j;
int main(){
    BST b;
    cin >> n;
    b.root = new node(1);
    fori(n-1){
        cin >> x >> y >> z;
        b.input(b.root,x);
        if(z == 0)
            need->left = new node(y);
        else 
            need->right = new node(y);
        need = NULL;
    }
    b.solution(b.root);
    cout << mx;
}