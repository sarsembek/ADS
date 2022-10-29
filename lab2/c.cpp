#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

struct linked_list
{
    node *head,*tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    node* get_tail(){
        node* cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        return cur;
    }
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
    }
};
int main(){
    int n;cin>>n;
    linked_list l;
    for(int i=0;i<n;i++){
        int j;cin>>j;
        if(i%2==0){
            l.add_node(j);
        }
    }
    l.display();
}