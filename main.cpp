#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct node {
  long long h1;
  long long h2;
  long long st_idx;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long n;
  cin >> n;
  long long big=0;

  while (n != 0) {
    big = 0;

    vector<int> v;
    stack<node> s;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }

    for (int i = 0; i < n; i++) {
      if (s.empty() && v[i]) {
        node *n = new node;
        *n = {1, v[i], i};
        s.push(*n);
        // cout << "pushed: (" << h1 << " ~ " << h2 << ", " << i << ")" << endl;

      } else {
        while (!s.empty()) {
          node &t = s.top();
          if (v[i] < t.h1) {

            long long tmp = (t.h2) * (i - t.st_idx);
            if (big < tmp) {
              big = tmp;
              // cout << "now: " << big << endl;
            }
            s.pop();
            // cout << "popped: (" << t.h1 << " ~ " << t.h2 << ", " << t.st_idx
            //      << ")" << endl;
            continue;

          } else if (v[i] >= t.h1 && v[i] < t.h2) {

            long long tmp = (t.h2) * (i - t.st_idx);
            if (big < tmp) {
              big = tmp;
              // cout << "now: " << big << endl;
            }
            // cout << "changed: from " << t.h2 << " to " << v[i] << endl;

            t.h2 = v[i];

          } else if (v[i] == t.h2) {

          } else if (v[i] > t.h2) {

            node *n = new node;
            *n = {t.h2+1, v[i], i};
            s.push(*n);
            // cout << "pushed: (" << h1 << " ~ " << h2 << ", " << i << ")" <<
            // endl;
          }
          break;
        }
      }
    }

    while (!s.empty()) {
      node &t = s.top();
      long long tmp = t.h2 * (n - t.st_idx);
      if (big < tmp) {
        big = tmp;
        // cout << "now: " << big << endl;
      }
      s.pop();
    }

    cout << big << "\n";
    cin >> n;
  }
}