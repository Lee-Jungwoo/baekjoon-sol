#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> s;

  int n;

  cin>>n;

  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x)
      s.push(x);
    else if(!s.empty())
      s.pop();
    else continue;
  }

  int cnt = 0;
  
  while(!s.empty()) {
    cnt += s.top();
    s.pop();
  }
  cout << cnt;
}