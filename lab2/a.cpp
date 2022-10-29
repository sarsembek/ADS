#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
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
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
    int findTheNearestNumber(int n){
        node *tmp;
        tmp = head;
        int dif=abs(n-tmp->data);
        int index=0;
        int ans=index;
        while(tmp!=NULL){
            if((dif>abs(n-tmp->data))&&dif!=abs(n-tmp->data)){
                dif=abs(n-tmp->data);
                ans=index;
            }
            tmp=tmp->next;
            index++;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    linked_list a;
    int x,b;
    while(n!=0){
        cin>>x;
        a.add_node(x);
        n--;
    }
    cin>>b;
    cout<<a.findTheNearestNumber(b);
    return 0;
}