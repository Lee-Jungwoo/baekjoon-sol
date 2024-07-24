#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct node {
  int value;
  int cnt = 1;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int c;
  cin >> c;

  vector<int> v;
  stack<node> s;

  for (int i = 0; i < c; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  long long cnt = 0;

  for (int i = 0; i < c; i++) {

    if (s.empty()) {

      node *n = new node;
      n->value = v[i];
      n->cnt = 1;
      s.push(*n);

      cout << "pushed " << v[i] << endl;
    } else {
      while (!s.empty()) {

        node top = s.top();

        if (v[i] > top.value) {
          s.pop();
          cout << "popped " << top.value << endl;
          cnt += top.cnt;
        } else if (v[i] < top.value) {
          node *n = new node;
          n->value = v[i];
          n->cnt = 1;
          s.push(*n);
          cnt++;
          cout << "pushed " << v[i] << endl;
          break;
        } else {
          // peel off, peek, and put back
          s.pop();
          if (!s.empty()) {
            cnt++;
          }
          cnt += top.cnt++;
          
          s.push(top);
          break;
        }
      }
      if (s.empty()) {
        node *n = new node;
        n->value = v[i];
        n->cnt = 1;
        s.push(*n);
        cout << "pushed " << v[i] << endl;
      }
    }
  }

  cout << cnt;
}