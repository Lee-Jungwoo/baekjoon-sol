#include <deque>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;

  cin >> n;
  deque<int> q;
  for (int i = 1; i <= n; i++) {
    q.push_back(i);
  }

  for (int i = 1; i < n; i++) {

    q.pop_front();
    int tmp = q.front();
    q.pop_front();
    q.push_back(tmp);
  }
  cout << q.back();
}