# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
int ans,sum = 0,min_sum = 0;
 
int findMaxSum(int n, Node *head) {
	while(head != NULL){
        sum += head->val;
        ans = max(ans,sum-min_sum);
        min_sum = min(min_sum,sum);
        head = head->next;
    }
    return ans;
}
 
int main() {
  int n;
  cin >> n;
  
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
  ans = head->val;
  cout << findMaxSum(n, head) << "\n";
  return 0;
}