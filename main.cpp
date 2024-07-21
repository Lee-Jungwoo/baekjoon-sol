#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main() {

  int n;
  cin >> n;

  list<int> l;
  list<int> result;
  stack<int> s;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    l.push_front(x);
  }

  for (auto e : l) {
    if (s.empty()) {
      result.push_front(-1);
      s.push(e);
    } else {
      while (!s.empty()) {
        int top = s.top();
        if (top > e) {
          result.push_front(top);
          s.push(e);
          break;
        } else if (top <= e) {
          s.pop();
        }
      }

      if (s.empty()) {
        result.push_front(-1);
        s.push(e);
      }
    }
  }

  for (auto e : result) {
    printf("%d ", e);
  }
}