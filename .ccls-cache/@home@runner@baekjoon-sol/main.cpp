#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct info {
  bool LR = false; // L, R -> true
  int value = 0;
  int index = 0;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int c;
  cin >> c;

  vector<int> v;
  info lr[500003][2]; // L -> 0, R -> 1
  stack<info> s;

  for (int i = 0; i < c; i++) {
    int x;
    cin>>x;
    v.push_back(x);
  }

  for (int i = 0; i < c; i++) {
    if (s.empty()) {
      lr[i][0].LR = true;
      lr[i][0].index = -1;
      info *tmp = new info;
      tmp->value = v[i];
      tmp->index = i;
      s.push(*tmp);
    } else {
      while (!s.empty()) {
        info top = s.top();
        if (v[i] > top.value) {
          s.pop();
        } else {
          lr[i][0].LR = false;
          lr[i][0].index = top.index;
          info *tmp = new info;
          tmp->value = v[i];
          tmp->index = i;
          s.push(*tmp);
        }
      }
      if (s.empty()) {
        lr[i][0].LR = true;
        lr[i][0].index = -1;
        info *tmp = new info;
        tmp->value = v[i];
        tmp->index = i;
        s.push(*tmp);
      }
    }
  } // left to right, find left big num

  // for (int i = c - 1; i >= 0; i--) {
  //   if (s.empty()) {
  //     lr[i][1].LR = true;
  //     lr[i][1].index = c;
  //     info *tmp = new info;
  //     tmp->value = v[i];
  //     tmp->index = i;
  //     s.push(*tmp);
  //   } else {
  //     while (!s.empty()) {
  //       info top = s.top();
  //       if (v[i] > top.value) {
  //         s.pop();
  //       } else {
  //         lr[i][1].LR = false;
  //         lr[i][1].index = top.index;
  //         info *tmp = new info;
  //         tmp->value = v[i];
  //         tmp->index = i;
  //         s.push(*tmp);
  //       }
  //     }
  //     if (s.empty()) {
  //       lr[i][1].LR = true;
  //       lr[i][1].index = c;
  //       info *tmp = new info;
  //       tmp->value = v[i];
  //       tmp->index = i;
  //       s.push(*tmp);
  //     }
  //   }
  // } // right to left, find right big num

  // int cnt = 0;
  // for (int i = 0; i < c; i++) {
  //   int idx = lr[i][1].index;

  //   if (idx == c) {
  //     cnt += c-i;
  //   } else if (lr[idx][0].index < idx) {
  //     cnt += idx - i;
  //   }
  // }

  // cout<<cnt;
}