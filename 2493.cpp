#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct node {
  int val;
  int index;
};

int main() {

  stack<node *> s;

  int n;
  int arr[500001] = {0};
  int resultArr[500001] = {0};
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  node *nod = new node;
  ;
  nod->index = 1;
  nod->val = arr[0];
  s.push(nod);
  node *tmp;

  for (int i = 1; i < n; i++) {

    while (!s.empty()) {
      tmp = s.top();
      if (arr[i] > tmp->val) {
        s.pop();
      } else {
        resultArr[i] = tmp->index;
        break;
      }
    }
    node *newnode = new node;
    newnode->index = i + 1;
    newnode->val = arr[i];
    s.push(newnode);

    cout << "after " << arr[i] << ", stack:" << endl;
    stack<node *> sss(s);
    while (!sss.empty()) {
      cout << sss.top()->val << ", " << sss.top()->index << endl;
      sss.pop();
    }
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    cout << resultArr[i] << " ";
  }
  cout << endl;
}