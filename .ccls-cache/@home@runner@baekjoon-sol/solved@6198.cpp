#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Node {
public:
  int h;
  int index;
};

int main() {
  int k;
  cin >> k;

  list<Node> l;
  stack<Node> st;
  unsigned int cnt = 0;

  for (int i = 0; i < k; i++) {
    int height;
    cin >> height;

    Node *n = new Node;
    n->h = height;
    n->index = k - i;

    l.push_front(*n);
  }

  for (auto i : l) {
    
    if (st.empty()) {
      cnt += i.index - 1;
      st.push(i);
    } else {
      while (!st.empty()) {
        Node &top = st.top();
        if (i.h > top.h) {
          st.pop();
          
        } else {
          cnt += (i.index - top.index - 1);
          st.push(i);
          break;
        }
      }

      if(st.empty()){
        cnt += i.index -1;
        st.push(i);
      }
      
    }
    
  }

  cout << cnt;
}