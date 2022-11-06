#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)
#define forj1(n) for(j = 1;j <= n;j++)
#define mp make_pair
#define pb push_back
#define MAX 1010
int a[MAX];
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

int i,j,n,k,l,r;
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
    void rev(node*nd){
        node * cur = nd;
        int cnt_l = -1,cnt_r = -1;
        while(cur->left != NULL){
            cur = cur->left;
            cnt_l++;
        }
        cur = nd;
        while(cur->right != NULL){
            cur = cur->right;
            cnt_r++;
        }
        cnt_l = min(cnt_l,cnt_r);
        while(cnt_l != -1){
            a[cnt_l]++;
            cnt_l--;
        }
    }
    void solution(node * ndd){
        rev(ndd);
        if(ndd->left != NULL){
            solution(ndd->left);
        }
        if(ndd->right != NULL){
            solution(ndd->right);
        }
    }
};   
BST b;
int main(){
    cin >> n;
    fori(n){
        cin >> k;
        b.insert(k);
    }
    node *N = b.root;
    b.solution(b.root);
    fori(n-1)
        cout << a[i] << " ";
}