#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  list<int> l;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s.compare("push") == 0) {
      int x;
      cin >> x;
      l.push_back(x);
    } else if (s.compare("pop") == 0) {
      if (l.empty()) {
        cout << -1 << '\n';
      } else {
        cout << l.front() << '\n';
        l.pop_front();
      }
    } else if (s.compare("size") == 0) {
      cout << l.size() << '\n';
    } else if (s.compare("empty") == 0) {
      cout << (l.empty() ? 1 : 0) << '\n';
    } else if (s.compare("front") == 0) {
      cout << (l.empty() ? -1 : l.front()) << '\n';
    } else if (s.compare("back") == 0) {
      cout << (l.empty() ? -1 : l.back()) << '\n';
    }
  }
}