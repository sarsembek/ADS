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
string s;
bool flag = false;
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
    void solution(node *cur,int i = 0){
        if(i == s.size())
            return;
        if(s[i] == 'L'){
            if(!cur->left){
                flag = true;
                return;
            }
            solution(cur->left,i+1);
        }else{
            //cout << 2;
            if(!cur->right){
                flag = true;
                return;
            }
            solution(cur->right,i+1);
        }
    }
    void answer(){
        solution(root);
        (flag)?cout << "NO\n":cout << "YES\n";
    }
};
int n,k,x,i,j;
int main(){
    BST b;
    cin >> n;
    cin >> k;
    fori(n){
        int x;cin >> x;
        b.insert(x);
    }
    while(k--){
        cin >> s;
        flag = false;
        b.answer();
    }
} 