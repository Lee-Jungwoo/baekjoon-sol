#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  int i = 0;
  int num = 1;
  int str[1100000] = {0};

  for (int j = 0; j < n; j++) {
    cin >> str[j];
  }

  stack<int> s;
  vector<char> result;

  while (i < n) {
    if (s.empty()) {
      s.push(num++);
      result.push_back('+');
    } else {
      int top = s.top();
      if (top < str[i]) {
        s.push(num++);
        result.push_back('+');
      } else if (top > str[i]) {
        cout << "NO";
        return 0;
      } else if (top == str[i]) {
        s.pop();
        i++;
        result.push_back('-');
      }
    }
  }

  for (auto i : result) {
    cout << i << '\n';
  }
}